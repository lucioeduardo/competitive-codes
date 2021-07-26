SELECT
	pd.name as pdname, pr.name as prname
FROM
	products as pd
INNER JOIN
	providers as pr
ON 
	pd.id_providers=pr.id
WHERE 
	pr.name='Ajax SA'