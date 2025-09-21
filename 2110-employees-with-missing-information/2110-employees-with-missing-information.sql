# Write your MySQL query statement below

SELECT e.employee_id FROM EMPLOYEES e LEFT JOIN SALARIES s ON e.employee_id = s.employee_id WHERE e.name is NULL OR s.salary is NULL
UNION 
SELECT s.employee_id FROM SALARIES s LEFT JOIN EMPLOYEES e   ON e.employee_id = s.employee_id WHERE e.name is NULL OR s.salary is NULL ORDER BY employee_id