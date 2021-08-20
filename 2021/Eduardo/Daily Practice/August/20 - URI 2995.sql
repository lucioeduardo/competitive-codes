SELECT
	temperature, count(mark)
FROM
	records
GROUP BY
	temperature, mark
ORDER BY
	mark