SELECT name, customers_number FROM(
  SELECT name, customers_number, 1 as filter FROM lawyers where customers_number = (SELECT MAX(customers_number) FROM lawyers)
  UNION
  SELECT name, customers_number, 2 as filter FROM lawyers where customers_number = (SELECT MIN(customers_number) FROM lawyers)
  UNION
  SELECT 'Average', ROUND(AVG(customers_number),0), 3 as filter from lawyers
) as table1 ORDER BY filter