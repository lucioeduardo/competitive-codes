SELECT
	distinct(p.id), p.name
FROM
	products as p 
INNER JOIN 
    categories as c
ON
	p.id_categories=c.id
WHERE
	c.name LIKE 'super%'