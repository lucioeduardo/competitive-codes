SELECT
	life_registry.name, ROUND(life_registry.omega*1.618,3) as "Fator N"
FROM
	life_registry
INNER JOIN
	dimensions
ON
	life_registry.dimensions_id=dimensions.id
WHERE
	(dimensions.name='C774' or dimensions.name='C875') 
AND
    life_registry.name like 'Richard%'
ORDER BY
	life_registry.omega