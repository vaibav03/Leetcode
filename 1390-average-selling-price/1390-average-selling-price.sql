# Write your MySQL query statement below
SELECT p.product_id, CASE 
    WHEN ROUND(SUM(price*units)/SUM(units),2)  IS NULL THEN 0 
    WHEN ROUND(SUM(price*units)/SUM(units),2) is not  NULL THEN ROUND(SUM(price*units)/SUM(units),2)
    END AS average_price 
    FROM PRICES p  LEFT JOIN UNITSSOLD us ON  us.product_id = p.product_id AND us.purchase_date BETWEEN p.start_date AND p.end_date GROUP BY product_id 