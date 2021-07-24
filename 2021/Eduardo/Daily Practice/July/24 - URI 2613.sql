SELECT
	m.id,m.name
FROM
	movies as m
INNER JOIN
	prices as p
ON 
	m.id_prices = p.id
WHERE
	p.value < 2