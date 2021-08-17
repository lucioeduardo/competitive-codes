WITH m (k, v) as (values ('A', 20.0),('B', 70.0),('C', 530.5))

SELECT
	name, m.v as price
FROM
	products JOIN m
ON
	m.k = products.type
ORDER BY
	products.type,
	products.id DESC