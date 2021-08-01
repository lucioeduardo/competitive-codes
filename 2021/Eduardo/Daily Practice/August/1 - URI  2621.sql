SELECT
	prod.name
FROM 
	products as prod
INNER JOIN
	providers as prov
ON
	prod.id_providers=prov.id
WHERE
	prod.amount between 10 and 20	
AND
	prov.name like 'P%'