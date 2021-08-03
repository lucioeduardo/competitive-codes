SELECT
	products.name as pname, categories.name
FROM
	products INNER JOIN categories
ON
	products.id_categories=categories.id
WHERE 
	products.amount > 100 AND categories.id=ANY('{1,2,3,6,9}'::int[])
ORDER BY
	categories.id