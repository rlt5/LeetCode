-- 596. Classes More Than 5 Students
-- SQL Schema
-- There is a table courses with columns: student and class

-- Please list out all classes which have more than or equal to 5 students.

-- For example, the table:

-- +---------+------------+
-- | student | class      |
-- +---------+------------+
-- | A       | Math       |
-- | B       | English    |
-- | C       | Math       |
-- | D       | Biology    |
-- | E       | Math       |
-- | F       | Computer   |
-- | G       | Math       |
-- | H       | Math       |
-- | I       | Math       |
-- +---------+------------+
-- Should output:

-- +---------+
-- | class   |
-- +---------+
-- | Math    |
-- +---------+

-- TEST CASES

-- {"headers": {"courses": ["student", "class"]}, "rows": {"courses": [["A", "Math"], ["B", "English"], ["C", "Math"], ["D", "Biology"], ["E", "Math"], ["F", "Computer"], ["G", "Math"], ["H", "Math"], ["I", "Math"]]}}
-- {"headers": {"courses": ["student", "class"]}, "rows": {"courses": []}}
-- {"headers": {"courses": ["student", "class"]}, "rows": {"courses": [["A", "Math"], ["B", "English"], ["C", "Math"], ["D", "Biology"], ["E", "Math"], ["F", "Math"], ["A", "Math"]]}}
-- {"headers": {"courses": ["student", "class"]}, "rows": {"courses": [["A", "Math"], ["B", "English"], ["C", "Math"], ["D", "Biology"], ["E", "Math"], ["F", "Math"], ["G", "Math"]]}}


-- # Write your MySQL query statement below

SELECT c class
FROM (SELECT class c, COUNT(class) as countClass
         FROM (SELECT DISTINCT student, class FROM courses) as s
        GROUP BY class) as t
WHERE countClass >= 5 AND c IS NOT NULL