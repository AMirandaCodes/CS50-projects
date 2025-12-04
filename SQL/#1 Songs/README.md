# Problem 1: Songs

## Project brief

This exercise works with a SQLite database of the **100 most-streamed songs on Spotify in 2018**.  
The task is to write eight SQL queries that answer specific questions about the songs and artists in `songs.db`.

The problem focuses on understanding the database schema, selecting data, sorting results, filtering using conditions, and using aggregate functions. Each query is written inside its corresponding file: `1.sql` through `8.sql`.

## Approach

This problem develops the skills with SQL fundamentals, including:

- Reading and understanding a database schema using `.schema`.
- Querying one or more tables with:

  - `SELECT`
  - `WHERE`
  - `ORDER BY`
  - `LIMIT`
  - aggregate functions like `AVG`
  - logical conditions with `AND`

- Returning only the columns specified in each task.

---

## My solution
### Description

For each of the provided .sql files, the program includes one query that:
1. Retrieves song names.
2. Sorts songs by tempo.
3. Finds the longest tracks.
4. Filters songs by musical characteristics.
5. Calculates the average energy.
6. Selects songs by specific artists.
7. Finds songs featuring "feat." in the title.

Each file contains a standalone SQL query, written so that it would still work even if the IDs in the database changed.

### How to use it
1. Navigate to the corresponding folder.
2. Open the database: `sqlite3 songs.db`.
3. Run a query of any of the files (`1.sql` to `8.sql`).

### Query snippets
**1.sql**
```sql
SELECT name
FROM songs;
```
**2.sql**
```sql
SELECT name
FROM songs
ORDER BY tempo;
```
**3.sql**
```sql
SELECT name
FROM songs
ORDER BY duration_ms DESC
LIMIT 5;
```
**4.sql**
```sql
SELECT name
FROM songs
WHERE danceability > 0.75
AND energy > 0.75
AND valence > 0.75;
```
**5.sql**
```sql
SELECT AVG(energy)
FROM songs;
```
**6.sql**
```sql
SELECT name
FROM songs
WHERE artist_id =
(
    SELECT id
    FROM artists
    WHERE name = 'Post Malone'
);
```
**7.sql**
```sql
SELECT AVG(energy)
FROM songs
JOIN artists ON songs.artist_id = artists.id
WHERE artists.name = 'Drake';
```
**8.sql**
```sql
SELECT name
FROM songs
WHERE name
LIKE '%feat.%';
```
