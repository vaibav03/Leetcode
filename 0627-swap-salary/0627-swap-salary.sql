# Write your MySQL query statement below
UPDATE SALARY
SET sex = CASE 
             WHEN sex = 'm' THEN 'f'
             WHEN sex = 'f' THEN 'm'
             ELSE sex
          END;
