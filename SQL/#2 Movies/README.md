# Problem 2: Movies

## Project brief

This exercise works with `movies.db`, a SQLite database containing IMDb-style information about movies, the people who directed and starred in them, and their ratings.  
The task is to write **twelve SQL queries**, each saved in its corresponding file: `1.sql` through `12.sql`.

Each query must output only the columns required by the specification. Queries must not assume specific `id` values for any movies or people—they should work even if the database changes.

## Approach

This problem developed my skills with relational databases and SQL, particularly:

- Reading a schema using `.schema`.
- Understanding how multiple tables interact (`movies`, `people`, `ratings`, `stars`, `directors`).
- Writing precise SQL queries using:
  - `SELECT`
  - `WHERE`
  - `ORDER BY`
  - `JOIN`
  - `AVG`, `COUNT`
  - subqueries
  - filtering with `LIKE`
  - `DISTINCT` record selection

Each `.sql` file contains one standalone query answering a specific question:
- Listing movies from specific years.
- Finding birth years of actors.
- Filtering movies by ratings.
- Joining tables to trace stars and directors.
- Using DISTINCT to avoid duplicates when a person worked on multiple films.

---

## My solution

### Description

The twelve `.sql` files include queries that:

1. List all movies released in 2008. 
2. Find Emma Stone’s birth year.  
3. List movies released in or after 2018 alphabetically.  
4. Count movies with a perfect 10.0 rating. 
5. List all Harry Potter films with release years in order.
6. Calculate the average rating of movies from 2012. 
7. List 2010 movies and their ratings, sorted by rating and title.
8. List all actors who starred in *Toy Story*.
9. List all actors who starred in any 2004 movie, ordered by birth year.
10. List directors of movies rated at least 9.0.  
11. List the top five highest-rated movies starring Chadwick Boseman.
12. List all movies featuring both Bradley Cooper and Jennifer Lawrence.

Each query returns exactly the information requested—no extra columns.

### How to use it
1. Navigate to the corresponding folder.
2. Open the database: `sqlite3 movies.db`
3. Run any query file.
4. If needed, check the schema to understand table relationships: `.schema`

### Query snippets
Below are a few representative examples of the style and structure used (not full solutions to all tasks).

**1.sql – Movies released in 2008**
```sql
SELECT title
FROM movies
WHERE year = 2008;
```

**2.sql – Birth year of Emma Stone**
```sql
SELECT birth
FROM people
WHERE name = 'Emma Stone';
```
**4.sql – Number of movies rated 10.0**
```sql
SELECT COUNT(*)
FROM ratings
WHERE rating = 10.0;
```

**8.sql – People who starred in Toy Story**
```sql
SELECT people.name
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.title = 'Toy Story';
```

**12.sql – Movies with both Bradley Cooper and Jennifer Lawrence**
```sql
SELECT title
FROM movies
WHERE id IN
(
    SELECT movie_id
    FROM stars
    WHERE person_id =
    (SELECT id FROM people WHERE name = 'Bradley Cooper')
)
AND id IN
(
    SELECT movie_id
    FROM stars
    WHERE person_id =
    (SELECT id FROM people WHERE name = 'Jennifer Lawrence')
);
```
