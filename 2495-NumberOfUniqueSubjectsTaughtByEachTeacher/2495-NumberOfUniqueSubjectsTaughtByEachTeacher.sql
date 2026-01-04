-- Last updated: 05/01/2026, 00:04:50
# Write your MySQL query statement below
SELECT teacher_id,COUNT(DISTINCT subject_id) as cnt FROM Teacher GROUP BY teacher_id;
-- SELECT subject_id,COUNT(subject_id) FROM Teacher GROUP BY subject_id;
