import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd, current_shares
from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    """Show portfolio of stocks"""
    # Gets user's current cash
    current_cash = (db.execute("SELECT cash FROM users WHERE id = ?",
                    session["user_id"]))[0]["cash"]

    if request.method == "GET":
        # List to add dictionaries for each of the user's stock
        summary = []

        # Variable to later display in HTML/Jinja: stocks’ total value + cash
        grand_total = current_cash

        # Gets the needed columns from the global_log table
        rows = db.execute(
            "SELECT stock, SUM(CASE WHEN action = 'Bought' THEN quantity ELSE -quantity END) AS total_shares FROM global_log WHERE username = ? GROUP BY stock HAVING total_shares > 0", session["username"])

        for row in rows:
            stock = row["stock"]

            # Uses the current_shares functions from helpers.py
            total_shares = current_shares(db, stock, session["username"])

            # Current price of one share and total holding value
            price = lookup(stock)["price"]
            holding_total = total_shares * price

            # Adds dictionary to summary list
            summary.append({
                "symbol": stock,
                "shares": total_shares,
                "price": price,
                "holding_total": round(holding_total, 2),
            })

            # Adds holding value to grand total
            grand_total += holding_total

        # Displays final grand total
        # Rounds to 2 decimal places to prevent floats calculations inaccuracies
        grand_total = round(grand_total, 2)

        return render_template("index.html", summary=summary, current_cash=current_cash, grand_total=grand_total)

    if request.method == "POST":
        extra = int(request.form.get("cash"))
        if not extra:
            return apology("Please put how much cash you want to add")
        if extra < 0:
            return apology("You can't add negative cash!")

        # Updates cash (uses current_cash variable)
        db.execute("UPDATE users SET cash = ? WHERE id = ?",
                   (current_cash + extra), session["user_id"])

        return redirect("/")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():  # TO DO
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        quote = lookup(symbol)

        # Checks symbol
        if not symbol:
            return apology("Plese insert a stock symbol")
        elif not symbol.isalpha():
            return apology("Symbol must be alphabetical")
        elif quote is None:
            return apology("That symbol doesn't exist")

        # Checks number of shares
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Number of shares must be numeric")

        if not shares:
            return apology("Please provide the number of shares")
        if shares < 0:
            return apology("You can't buy a negative number of shares")

        # Calculates cost and substract of user's cash
        price = quote["price"]
        cost = shares * price
        row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash_available = row[0]["cash"]
        if (cash_available - cost) < 0:
            return apology("You don't have enough cash!")

        # Updates cash available to the user
        cash_available = cash_available - cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_available, session["user_id"])

        # Updates global log table
        db.execute("INSERT INTO global_log (username, action, stock, price, quantity, date, time) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   session["username"], "Bought", symbol, price, shares, datetime.now().strftime("%m/%d/%Y"), datetime.now().strftime("%H:%M"))

        return redirect("/")

    if request.method == "GET":
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # Selects relevant columns from global_log table
    rows = db.execute(
        "SELECT action, stock, price, quantity, date, time FROM global_log WHERE username = ? ORDER BY date DESC, time DESC", session["username"])

    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        session["username"] = rows[0]["username"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():  # TO DO
    """Get stock quote."""
    if request.method == "POST":
        findings = lookup(request.form.get("symbol"))

        # If lookup returns None
        if findings == None:
            return apology("That stock symbol doesn't exist")
        else:
            return render_template("quoted.html", findings=findings)

    if request.method == "GET":
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():  # TO DO
    """Register user"""
    # User submitting the register form
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Checks no fields are blank
        if not username:
            return apology("A username is required")
        if not password:
            return apology("A password is required")
        if not confirmation:
            return apology("Please confirm your password")

        # Checks password and confirmation match
        if password != confirmation:
            return apology("Password and confirmation do not match")

        # Hash password
        hashed_pass = generate_password_hash(password)

        # Stores username and hashed password, unless username exists
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hashed_pass)
        except ValueError:
            return apology("This username already exists")

        return redirect("/")

    # User accesses the page, without submitting a form
    if request.method == "GET":
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    # Selects all different stocks the user has
    stocks = db.execute(
        "SELECT stock, SUM(CASE WHEN action='Bought' THEN quantity ELSE -quantity END) AS total_shares FROM global_log WHERE username = ? GROUP BY stock HAVING total_shares > 0", session["username"])

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Selects cash the user currently has
        row = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        # Checks for errors
        if not symbol:
            return apology("Please select a stock")
        if not shares:
            return apology("Please provide a number of shares")
        if int(shares) < 0:
            return apology("Number of shares must be a positive number")

        # Uses the current_shares functions from helpers.py
        available = current_shares(db, symbol, session["username"])

        if available < int(shares):
            return apology("You don't have enough shares of this type")

        # Updates user's cash and stock
        cash_available = row[0]["cash"]
        price = lookup(symbol)["price"]
        cost = int(shares) * price

        cash_available = cash_available + cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash_available, session["user_id"])

        # Updates global history tracker
        db.execute("INSERT INTO global_log (username, action, stock, price, quantity, date, time) VALUES (?, ?, ?, ?, ?, ?, ?)",
                   session["username"], "Sold", symbol, price, shares, datetime.now().strftime("%m/%d/%Y"), datetime.now().strftime("%H:%M"))

        return redirect("/")

    if request.method == "GET":
        return render_template("sell.html", stocks=stocks)
