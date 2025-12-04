# Problem 3: Fiftyville

## Project brief

This exercise presents a mystery set in the town of **Fiftyville**, where the **CS50 Duck has been stolen**.  
Using only the information stored inside a SQLite database (`fiftyville.db`), the task is to determine:

1. **Who the thief is**  
2. **Which city the thief fled to**  
3. **Who the accomplice was who helped plan the escape**

The theft occurred on **July 28, 2024**, on **Humphrey Street**, and all clues must be uncovered through SQL queries.  
The problem focuses on investigative reasoning using a relational database and documenting the entire process in `log.sql`.

Two files must be submitted:

- `log.sql` — a detailed log of every query executed, with comments explaining the reasoning behind each step.  
- `answers.txt` — the final conclusions: thief, destination city, accomplice.

---

## Approach

This problem developed my skills with:

- Reading and exploring a relational schema using `.schema`
- Investigative querying with:
  - `SELECT`
  - `JOIN`
  - filtering with `WHERE`
  - `LIKE`
  - time-based conditions
  - cross-referencing multiple tables
- Building logical deductions from:
  - crime scene reports  
  - interview transcripts  
  - ATM transactions  
  - phone call logs  
  - flight records  
  - bakery security logs  
- Keeping a clear, readable query log using SQL comments

The process mirrors real-world data investigation: progressively narrowing suspects by combining clues across different tables.

---

## My solution

### Description

In `log.sql`, I recorded every step of the investigation, including intermediate checks to understand table structure, followed by targeted queries that narrowed down suspects.

Key deductions included:

1. **From the crime scene report**  
   - Theft took place at **10:15 AM** at **Humphrey Street Bakery**.  
   - Three interviews referenced the bakery.

2. **From interviews**  
   - The thief fled the bakery parking lot within 10 minutes.  
   - They withdrew cash from an ATM on **Leggett Street** earlier that morning.  
   - They made a short (<60 seconds) phone call shortly after the theft.  
   - Their accomplice bought the *earliest flight out of Fiftyville* on July 29.

3. **From bakery security logs**  
   - Identified all people whose cars exited between **10:15 and 10:25 AM**.

4. **From ATM transactions**  
   - Cross-referenced suspects with those who withdrew money from the Leggett Street ATM.

5. **From phone call records**  
   - Identified suspects with short calls on July 28.

6. **From flights and passengers**  
   - Found the earliest flight out of Fiftyville on July 29.  
   - Determined which suspect was on that flight.  
   - Identified the destination city.  
   - Identified the accomplice via the phone record linking both.

The final answers were then placed in `answers.txt`.

---

## Instructions

1. Navigate to the corresponding project folder.
2. Open the database: `sqlite3 fiftyville.db`
3. Inspect the schema to understand all tables and relationships: `.schema`
4. Execute any query by writing it directly or by keeping track in `log.sql`.
5. Once the investigation is complete, fill in the final results in `answers.txt` without modifying the file structure.

### Query snippets
Below are representative examples of some of the SQL queries used during the investigation (shortened for clarity).
The complete investigation is documented in `log.sql`.

**Crime scene report**
```sql
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';
```

**Interview transcripts mentioning the bakery**
```sql
SELECT transcript
FROM interviews
WHERE year = 2024
AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';
```

**Cars that left the bakery parking lot within 10 minutes**
```sql
SELECT name
FROM people AS p
JOIN bakery_security_logs AS b
ON p.license_plate = b.license_plate
WHERE b.year = 2024
AND b.month = 7 AND b.day = 28
AND b.activity = 'exit'
AND b.hour = 10
AND b.minute BETWEEN 15 AND 25;
```

**People who withdrew money at the Leggett Street ATM**
```sql
SELECT p.name
FROM people AS p
JOIN bank_accounts AS ba ON p.id = ba.person_id
JOIN atm_transactions AS a ON ba.account_number = a.account_number
WHERE a.year = 2024 AND a.month = 7 AND a.day = 28
AND a.atm_location = 'Leggett Street'
AND a.transaction_type = 'withdraw';
```
