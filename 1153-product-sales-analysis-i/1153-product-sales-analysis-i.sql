# Write your MySQL query statement below
SELECT Product.Product_name, Sales.year, Sales.price FROM 
 PRODUCT JOIN SALES ON Product.product_id = Sales.product_id 