SELECT
	c.name, o.id
FROM
	customers as c
INNER JOIN
	orders as o
ON
	c.id = o.id_customers
WHERE
	extract(year from o.orders_date)=2016
AND
	extract(month from o.orders_date) between 1 and 6