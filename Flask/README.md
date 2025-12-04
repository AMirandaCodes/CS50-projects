# Module 9 – Flask

This module introduced server-side web development using **Flask**, a lightweight Python web framework.  
Throughout the problem set, I learned how to build dynamic web applications that use **routes**, **templates (Jinja)**, **HTML forms**, and **SQLite databases**.  
I also practiced integrating APIs, managing user sessions, and implementing full CRUD operations.

## Problem Set 9

### 1. Birthdays

### **Task**
Build a Flask web application that lets users **store and view friends’ birthdays** using a SQLite database.

### **Key Requirements**
- Display all saved birthdays on page load (GET).
- Provide a form to add a new birthday (POST).
- Validate user input and insert new rows into the database.
- Use Jinja to loop through database rows and render each entry in a table.

### **Concepts Covered**
- Flask routing (`GET` and `POST`)
- SQLite database queries
- Rendering templates with Jinja
- Processing form submissions
- Server-side input handling
- HTML tables and templating logic

### 2. Finance

### **Task**
Implement a full-featured stock trading web app inspired by CS50 Finance (“C$50 Finance”).  
Users can register, log in, quote real stock prices, buy/sell shares, and track their portfolio.

### **Core Features**
- User registration and login with hashed passwords
- Real-time stock price lookup via a stock API
- Buy and sell shares with dynamic balance updates
- Portfolio overview showing owned stocks and current values
- Transaction history page
- Input validation and error handling

### **Concepts Covered**
- Flask sessions and authentication
- Database schema design (users, transactions, holdings)
- Using APIs and JSON responses
- Implementing business logic (validating shares, checking balance)
- Templating with Jinja
- Formatting currency and tables
- State persistence via SQLite
