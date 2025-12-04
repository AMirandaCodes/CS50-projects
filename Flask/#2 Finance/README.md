# Problem 2: Finance

## Project brief
This project consists of creating **C$50 Finance**, a Flask-based web application that allows users to simulate buying and selling stocks using real-time price data from an external API.

The application includes:

- User registration and login
- Real-time stock lookup
- Buying and selling of shares
- Portfolio overview with current prices and total value
- Transaction history
- Secure handling of cash balance and share counts

The task is to implement the entire backend logic, complete all HTML templates, and manage user data using a **SQLite** database.

## Approach
This problem developed my skills with **full-stack web development**, strengthening concepts such as:

- Flask routing and Jinja templating
- Server-side form handling and input validation
- Using APIs to fetch live stock data
- Managing user sessions and authentication
- SQL queries for inserting, updating, and retrieving data
- Maintaining consistency between tables (users, transactions, cash balance)
- Displaying dynamic portfolio data with updated market prices

The project consolidates everything from prior problems into a realistic, multi-page web application with persistent storage and external API usage.

---

## My solution

### Description
My implementation of C$50 Finance includes the following features:

- **Register & Log In**: Secure password hashing and user session handling.
- **Quote Lookup**: A user can search for a stock symbol, and the app displays real market data.
- **Buy Stocks**: Validates:
  - The symbol exists  
  - The share count is a positive integer  
  - The user can afford the purchase
  - Then records the transaction and updates the cash balance.
- **Sell Stocks**: Ensures:
  - The stock belongs to the user  
  - They have enough shares to sell
  - Then updates holdings and adds cash.
- **Portfolio (Home) Page**: Displays:
  - Each owned stock  
  - Current price (via API)  
  - Total value per stock  
  - Grand total (stocks + cash)
- **History Page**: Shows all transactions (buy/sell), including price and timestamp.

The logic is contained in `app.py`, using helper functions from `helpers.py`, and rendered through Jinja templates.

### How to use it
1. Open the corresponding folder. 
2. Run the Flask server: `flask run`.
3. Open the provided link in your browser.
4. Register a new account.
5. Use the navigation bar to:
   - Look up stock prices
   - Buy or sell shares
   - View your portfolio
   - Check transaction history

The app simulates real trading using real-time prices, but without using real money.

### Code snippet
Below is a minimal structure of `app.py` showing how routes are defined.

>Full implementation and other files used can be found in the folder
```python
from flask import Flask, render_template, request, redirect, session
from cs50 import SQL
from helpers import apology, login_required, lookup, usd

app = Flask(__name__)
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    # Portfolio logic here. See full file for the complete code.
    return render_template("index.html")

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    # Buy logic here. See full file for the complete code.
    return render_template("buy.html")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    # Sell logic here. See full file for the complete code.
    return render_template("sell.html")

```
