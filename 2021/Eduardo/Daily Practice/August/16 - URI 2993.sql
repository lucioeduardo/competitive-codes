SELECT
	amount as most_frequent_value
FROM
	value_table
GROUP BY amount
ORDER BY count(*) DESC
LIMIT 1