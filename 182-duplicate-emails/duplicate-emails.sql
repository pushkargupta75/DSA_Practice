# Write your MySQL query statement below
select email as Email 
from Person 
group by 1
having count(*)>1;