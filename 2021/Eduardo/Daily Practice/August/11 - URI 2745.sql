SELECT
	name, ROUND(0.10*salary,2) as tax
FROM
	people
WHERE
	salary > 3000