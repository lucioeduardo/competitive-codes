SELECT clients.name, clients.investment, min(month) as month_of_payback, 
	min(month_sum)-clients.investment as return
FROM
	(SELECT
        client_id, month,
        (SELECT SUM(profit) FROM operations as op WHERE client_id=operations.client_id AND month <= operations.month) as month_sum
    FROM
        operations
    ORDER BY client_id, month) as sl
INNER JOIN
	clients ON clients.id=client_id
WHERE
	month_sum >= clients.investment
GROUP BY
	client_id, clients.name, clients.investment
ORDER BY
	return DESC