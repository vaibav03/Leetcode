# Write your MySQL query statement below
WITH min_year AS
(SELECT  product_id,MIN(year) as first_year FROM Sales GROUP BY PRODUCT_ID)

SELECT min_year.product_id ,first_year,quantity,price FROM min_year JOIN Sales on min_year.product_id = Sales.product_id AND min_year.first_year = Sales.year
