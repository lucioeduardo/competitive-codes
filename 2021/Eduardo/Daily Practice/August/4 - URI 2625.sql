SELECT
	REGEXP_REPLACE(cpf, '([0-9]{3})([0-9]{3})([0-9]{3})([0-9]{2})', '\1.\2.\3-\4') as CPF
FROM
	natural_person