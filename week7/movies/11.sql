SELECT movies.title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
JOIN ratings ON ratings.movie_id = movies.id
WHERE people.name LIKE 'Chadwick Boseman'
ORDER BY ratings.rating ASC
LIMIT 5;
