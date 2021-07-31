SELECT
	p.name, f.name as fornecedor, p.price
FROM 
	products as p
INNER JOIN
	providers as f
ON 
	p.id_providers=f.id
INNER  JOIN
	categories as c
ON
	p.id_categories=c.id
WHERE
	p.price>1000 and c.name='Super Luxury'