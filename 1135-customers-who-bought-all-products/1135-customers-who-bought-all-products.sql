# Write your MySQL query statement below
SELECT CUSTOMER_ID  FROM CUSTOMER c JOIN PRODUCT p ON c.product_key = p.product_key 
GROUP BY CUSTOMER_ID HAVING COUNT(DISTINCT p.product_key ) = (SELECT COUNT(*) FROM PRODUCT)