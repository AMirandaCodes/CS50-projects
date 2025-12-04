# Module 7 – SQL

This module introduced the fundamentals of relational databases, focusing on how to query, filter, join, and aggregate data using SQL.  
Through three problem sets—**Songs**, **Movies**, and **Fiftyville**— I practised reading real-world datasets, exploring schemas, and writing efficient SQL queries to extract insights and solve a real investigative puzzle.

## Problem set 7

### 1. Songs

- **Task**: Query a Spotify dataset (`songs.db`) containing the 100 most-streamed songs of 2018.  
  Write SQL queries (`1.sql`–`8.sql`) to extract information such as song names, ordering by tempo or duration, selecting songs with high audio-feature values, computing average energy, and finding songs by or featuring particular artists.

- **Concepts**:  
  - Inspecting schema (`.schema`)  
  - `SELECT`, `WHERE`, `ORDER BY`, `LIMIT`  
  - Aggregate functions (`AVG`)  
  - Pattern matching with `LIKE`  
  - Filtering and sorting  
  - Avoiding assumptions about primary keys and ids

- **Representative queries**:  
  - List all song names.  
  - Songs ordered by increasing tempo.  
  - Top 5 longest songs (by duration).  
  - Songs with danceability, energy, and valence > 0.75.  
  - Average energy across all songs.  
  - Songs by a given artist (e.g., Post Malone) without assuming artist_id.  
  - Songs whose names include `"feat."`.

### 2. Movies

- **Task**: Query an IMDb-like database (`movies.db`) to answer questions about films, people (actors/directors), and ratings.  
  Write single-statement SQL queries (`1.sql`–`13.sql`) using joins, aggregates, and sorting.

- **Concepts**:  
  - Multi-table `JOIN`s (movies, people, ratings, cast, crew)  
  - Filtering by year, name, rating, and title patterns  
  - Aggregation (`COUNT`, `AVG`) and `GROUP BY` when needed  
  - Ordering results with `ORDER BY` (multi-column ordering)  
  - Ensuring uniqueness in results where required

- **Representative queries**:  
  - All movies from 2008.  
  - Birth year lookup for a person (Emma Stone).  
  - Movies released ≥ 2018, alphabetically.  
  - Number of movies with a 10.0 rating.  
  - Titles + years of all Harry Potter movies in chronological order.  
  - Average rating for movies released in 2012.  
  - Movies (2010) with ratings ordered by rating (desc) then title.  
  - Names of cast for a specific movie (e.g., Toy Story).  
  - Directors who directed movies rated ≥ 9.0.  
  - Highest-rated movies for a given actor (e.g., Chadwick Boseman).  
  - Movies appearing in common between two actors (e.g., Bradley Cooper & Jennifer Lawrence).  
  - People who co-starred with Kevin Bacon (born 1958), excluding Bacon himself.

### 3. Fiftyville

- **Task**: Use a provided forensic database (`fiftyville.db`) to solve a local mystery: determine **who the thief is**, **which city they escaped to**, and **who the accomplice was**—given that the theft occurred on **July 28, 2024** on **Humphrey Street**.  
  Record your investigative process in `log.sql` (annotated SQL queries) and submit the final answers in `answers.txt`.

- **What to produce**:  
  - `log.sql` — a chronological, commented log of the SQL queries ran while investigating  
  - `answers.txt` — to fill in the three required answers (thief name, escape city, accomplice name)

- **Concepts**:  
  - Schema exploration (`.tables`, `.schema table_name`) to discover relevant tables/columns  
  - Targeted `SELECT` queries to filter by date and location (crime scene reports)  
  - Joining tables (e.g., people, vehicles, flights, addresses, surveillance) to connect individuals with events  
  - Using timestamps, locations, and associative tables to infer movements and accomplices  
  - Iterative refinement: start broad, then filter results to the date/location, then trace related records
