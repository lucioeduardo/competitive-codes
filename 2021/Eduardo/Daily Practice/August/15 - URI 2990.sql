SELECT
	empregados.cpf, empregados.enome, departamentos.dnome
FROM
	empregados INNER JOIN departamentos ON empregados.dnumero=departamentos.dnumero
WHERE
	(SELECT count(*) FROM trabalha WHERE cpf_emp=empregados.cpf)=0
ORDER BY empregados.cpf