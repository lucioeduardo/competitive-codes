SELECT
	dpto as "Nome Departamento", count(*) as "Numero de Empregados", ROUND(avg(salario),2) as "Media salarial",
    ROUND(max(salario),2) as "Maior Salario", 
    CASE WHEN min(salario) != 0 THEN ROUND(min(salario),2)
    	ELSE '0'
    END as "Menor Salario"
FROM
    (SELECT
        empregado.nome, departamento.nome as dpto, COALESCE(SUM(vencimento.valor),0) - 
        COALESCE((SELECT SUM(valor) FROM emp_desc INNER JOIN desconto ON desconto.cod_desc = emp_desc.cod_desc WHERE emp_desc.matr = empregado.matr),0) 
        as salario
    FROM
        empregado 
        INNER JOIN departamento ON departamento.cod_dep=empregado.lotacao
        LEFT JOIN emp_venc ON emp_venc.matr=empregado.matr
        LEFT JOIN vencimento ON vencimento.cod_venc=emp_venc.cod_venc
    GROUP BY empregado.nome,departamento.nome,empregado.matr) as sl
GROUP BY dpto
ORDER BY "Media salarial" DESC