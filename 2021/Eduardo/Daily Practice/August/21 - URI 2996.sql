SELECT
	packages.year, (SELECT name FROM users where id=packages.id_user_sender) as sender, 
    (SELECT name FROM users where id=packages.id_user_receiver) as receiver     
FROM
	packages
WHERE
	(packages.color='blue' OR packages.year=2015)
    AND
    (SELECT address FROM users where id=packages.id_user_sender) != 'Taiwan'
    AND
    (SELECT address FROM users where id=packages.id_user_receiver) != 'Taiwan'
ORDER BY year DESC, id_package DESC