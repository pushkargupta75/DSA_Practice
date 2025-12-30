# Write your MySQL query statement below
select Register.contest_id,round(count(user_id)*100/(select count(*) from Users),2) as percentage
from Register
inner join Users
using(user_id)
group by 1
order by percentage desc,contest_id;