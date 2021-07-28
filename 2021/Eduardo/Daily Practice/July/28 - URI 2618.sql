SELECT
	p.name as pd, pr.name as pr, c.name as cat
FROM
	products as p
INNER JOIN
	providers as pr
ON 
	p.id_providers=pr.id
INNER JOIN
	categories as c
ON 
	p.id_categories=c.id
WHERE
	pr.name='Sansul SA'
AND
	c.name='Imported'
