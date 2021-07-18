SELECT 
  products.name AS pd,providers.name AS pv FROM products 
INNER JOIN 
  providers on products.id_providers=providers.id 
WHERE 
  products.id_categories=6