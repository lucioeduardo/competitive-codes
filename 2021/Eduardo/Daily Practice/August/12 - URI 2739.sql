SELECT
	name, CAST(EXTRACT(day from payday) AS INT) as day
FROM
	loan