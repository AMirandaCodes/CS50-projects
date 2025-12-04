-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find crime scene description
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';
    -- FINDINGS FROM QUERY: Theft at 10:15am, Humphrey Street bakery.
    -- 3 interviews conducted, all mentioning the bakery. Littering at 16:36, no known witnesses.

-- Check interview transcripts
SELECT transcript FROM interviews
WHERE year = 2024
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';
    -- FINDINGS FROM QUERY: Sometime within 10min of the theft, a car left the bakery parking lot.
    -- Thief withdrew money from ATM on Leggett Street, before witness got to Emma's bakery
    -- Thief had a phone call for less than a minute after theft.
    -- On the call, thief asked accomplice to purchase the earliest flight out of Fiftywille the next day.

-- Understanding bakery security logs: Activity
SELECT DISTINCT activity
FROM bakery_security_logs;
    -- FINDINGS FROM QUERY: Security logs register 'entrance' and 'exit'

-- Names of whoever owns a car that left the bakery car park any time within 10 min of the theft
SELECT name
FROM people AS p
JOIN bakery_security_logs AS b
ON p.license_plate = b.license_plate
WHERE b.month = 7
AND b.day = 28
AND b.year = 2024
AND b.activity = 'exit'
AND b.hour = '10'
AND b.minute BETWEEN 15 AND 25
ORDER BY p.name;
    -- FINDINGS FROM QUERY: Barry, Bruce, Diana, Iman, Kelsey, Luca, Sofia, Vanessa

-- Understanding ATM transactions table: ATM location & Transaction type
SELECT DISTINCT atm_location, transaction_type
FROM atm_transactions;
    -- FINDINGS FROM QUERY: Street name, deposit/withdraw

-- Names of whoever withdrew from ATM before theft (10:15am)
SELECT p.name
FROM people AS p
JOIN bank_accounts AS b ON p.id= b.person_id
JOIN atm_transactions AS a ON b.account_number = a.account_number
WHERE a.year = 2024
AND a.month = 7
AND a.day = 28
AND a.atm_location = 'Leggett Street'
AND a.transaction_type = 'withdraw'
ORDER BY p.name;
    -- FINDINGS FROM QUERY: Benista, Brooke, Bruce, Diana, Iman, Kenny, Luca, Taylor

-- Names of who had a call less of 60s that day
SELECT p.name FROM people AS p
JOIN phone_calls AS phcal ON p.phone_number = phcal.caller
WHERE phcal.year = 2024
AND phcal.month = 7
AND phcal.day = 28
AND phcal.duration < 60
ORDER BY p.name;
    -- FINDINGS FROM QUERY: Benista, Bruce, Carina, Diana, Kelsey, Kelsey, Kenny, Sofia, Taylor
    -- Bruce and Diana listed in all queries so far = Final suspects

-- List of passengers of earliest flight from Fiftyville next day (July 29th)
SELECT p.name FROM people AS p
JOIN passengers AS pas ON p.passport_number = pas.passport_number
JOIN flights AS f ON pas.flight_id = f.id
JOIN airports AS a ON f.origin_airport_id = a.id
WHERE a.city = 'Fiftyville'
AND f.id =
(
    SELECT id FROM flights
    WHERE year = 2024
    AND month = 7
    AND day = 29
    ORDER BY hour, minute
    LIMIT 1
);
    -- FINDINGS FROM QUERY: Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny, Luca
    -- Bruce is the thief! The only one who appeared in all queries.

-- Find out the city he escaped to (using flight ID of earliest flight of the day)
SELECT city FROM airports
WHERE id =
(
    SELECT destination_airport_id FROM flights
    WHERE year = 2024
    AND month = 7
    AND day = 29
    ORDER BY hour, minute
    LIMIT 1
);
    -- FINDING FROM QUERY: The thief escaped to New York City!


-- Finding out name of accompliance (whoever was called by the thief after theft)
SELECT name from people AS p
JOIN phone_calls AS phcal ON p.phone_number = phcal.receiver
WHERE phcal.id =
(
    SELECT id FROM phone_calls
    WHERE year = 2024
    AND month = 7
    AND day = 28
    AND duration < 60
    AND caller =
    (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
);
    -- FINDING FROM QUERY: Robin is the accomplice!
