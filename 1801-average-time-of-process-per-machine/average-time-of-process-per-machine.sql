# Write your MySQL query statement below
SELECT 
    st.machine_id,
    ROUND(AVG(end.timestamp - st.timestamp), 3) as processing_time
FROM 
    Activity as st
CROSS JOIN Activity as end
    ON (
            st.machine_id = end.machine_id
        AND st.process_id = end.process_id
        AND st.activity_type = "start"
        AND end.activity_type = "end"
    )
GROUP BY st.machine_id
;