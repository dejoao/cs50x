SELECT movies.title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE people.name LIKE 'Bradley Cooper' 
   OR people.name LIKE 'Jennifer Lawrence';
