-- Write your PostgreSQL query statement below
SELECT T.id
FROM Weather T
CROSS JOIN Weather Y
WHERE (T.recordDate - Y.recordDate) = 1
    AND T.temperature > Y.temperature
;