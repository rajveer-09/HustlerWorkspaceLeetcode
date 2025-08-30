# Write your MySQL query statement below
SELECT
    S.user_id,
    ROUND(
        IFNULL(
            SUM(CASE WHEN C.action = 'confirmed' THEN 1 ELSE 0 END) / COUNT(C.user_id),
            0
        ), 2
    ) AS confirmation_rate
FROM
    Signups AS S
LEFT JOIN
    Confirmations AS C ON S.user_id = C.user_id
GROUP BY
    S.user_id;