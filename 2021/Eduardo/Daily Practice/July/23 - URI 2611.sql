SELECT
	p.id, p.name
FROM
	movies as p 
INNER JOIN
	genres as g
ON
	p.id_genres=g.id
WHERE
	g.description='Action'