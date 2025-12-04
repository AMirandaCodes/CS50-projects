SELECT name FROM ratings, people, directors
WHERE directors.movie_id = ratings.movie_id
AND directors.person_id = people.id
AND rating >= 9.0;
