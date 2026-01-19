# Write your MySQL query statement below
select m.employee_id,m.name,count(e.employee_id) as reports_count,round(avg(e.age)) as average_age
from Employees as e
inner join Employees as m
on(e.reports_to=m.employee_id)
group by 1
order by 1;