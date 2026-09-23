# Write your MySQL query statement below
SELECT w.id
FROM Weather w
 JOIN Weather r
ON  r.recordDate= DATE_SUB(w.recordDate,INTERVAL 1 DAY)
WHERE w.temperature>r.temperature;