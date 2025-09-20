# Write your MySQL query statement below

SELECT s.user_id , COALESCE(ROUND(SUM(CASE WHEN c.ACTION = 'confirmed' THEN 1
 WHEN c.ACTION = 'timeout' THEN 0
END 
)/COUNT(*),2),0) as confirmation_rate FROM SIGNUPS s LEFT JOIN CONFIRMATIONS  c ON  s.user_id = c.user_id GROUP BY s.user_id