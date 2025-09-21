# Write your MySQL query statement below
SELECT sp.NAME FROM Salesperson sp WHERE sales_id NOT IN  (
    SELECT o.sales_id FROM COMPANY c JOIN Orders o ON c.com_id = o.com_id WHERE c.name = 'RED' 
 ) 
