# Problem 1: Birthdays

## Project Brief
This project involved creating a web application to store and track friends' birthdays using Flask, SQLite, and HTML/CSS. The application allows users to:
- View all stored birthdays in a clean, tabular format.
- Add new birthdays through a web form.
- Have data persistently stored in a SQLite database.

The technical requirements included:
- Implementing a Flask backend with two route handlers (`GET` and `POST`) for the `/` path.
- Designing an HTML form with proper input validation (name, month, and day).
- Using SQL queries to retrieve and insert data into the `birthdays.db` database.
- Rendering dynamic content in the template using Jinja2 syntax.
- Ensuring proper form validation to handle missing or incorrect input.

## Approach
This problem developed my skills with full-stack web development, integrating:
- Backend development with Flask and Python.
- Database interaction using SQL via CS50's SQL wrapper.
- Frontend templating with Jinja2 for dynamic HTML generation.
- Form handling and input validation.
- Web application structure with separation of concerns (templates, static files, application logic).

The application follows a classic Model-View-Controller (MVC) pattern where:
- The database serves as the model.
- `index.html` templates serve as the view.
- `app.py` contains the controller logic.

---

# My Solution

## Description
The Birthday Tracker application consists of:
1. A clean, responsive interface with two main sections:
- An "Add a Birthday" form with three input fields (name, month, day) and validation.
- An "All Birthdays" table displaying all stored birthdays.

2. Backend functionality that:
- Retrieves all birthdays from the database on `GET` requests.
- Processes form submissions on `POST` requests.
- Validates input before inserting into the database.
- Redirects to the main page after successful additions.

3. Database operations using:
- `SELECT * FROM birthdays` to fetch all records.
- `INSERT INTO birthdays` to add new records with proper parameterization.

### How to Use It
1. Navigate to the corresponding folder.
2. Run: `flask run`.
3. Open your browser to `http://localhost:5000`.
4. Add a new birthday by filling the name, month, and day fields.
5. Click "Add Birthday". The page will refresh with the new birthday added to the table.

### Code Structure
`app.py` (Backend Controller)
```python
@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        # Extract and validate form data
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        
        # Basic validation - redirect if any field is empty
        if not name or not month or not day:
            return redirect("/")
        
        # Insert into database
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        
        return redirect("/")
    
    else:
        # GET request - retrieve all birthdays
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)
```
`index.html` (Frontend Template)
```html
<!-- Form for adding new birthdays -->
<form action="/" method="post">
    <input type="text" name="name" placeholder="Name">
    <input type="number" name="month" placeholder="Month" min="1" max="12">
    <input type="number" name="day" placeholder="Day" min="1" max="31">
    <input type="submit" value="Add birthday">
</form>

<!-- Table displaying all birthdays -->
<table>
    <tbody>
        {% for person in birthdays %}
        <tr>
            <td>{{ person.name }}</td>
            <td>{{ person.month }}/{{ person.day }}</td>
        </tr>
        {% endfor %}
    </tbody>
</table>
```
`styles.css` (Provided Styling)
