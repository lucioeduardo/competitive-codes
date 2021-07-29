SELECT	
	c.id, c.name
FROM
	customers as c 
LEFT JOIN
	locations as l
ON 
	c.id=l.id_customers
WHERE 
	l.id_customers is NULL