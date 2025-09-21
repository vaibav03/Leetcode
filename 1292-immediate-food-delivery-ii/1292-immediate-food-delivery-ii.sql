# Write your MySQL query statement below
WITH ans AS (SELECT customer_id , CASE WHEN MIN(order_date) = MIN(customer_pref_delivery_date) THEN 1 ELSE 0 END  AS first_order FROM Delivery GROUP BY CUSTOMER_ID)

SELECT ROUND(SUM(first_order) / COUNT(*) * 100,2) AS immediate_percentage FROM ans 