# Write your MySQL query statement below
(select u.name as results
from Users u
inner join MovieRating m
using(user_id)
group by user_id,name
order by count(*) desc,u.name asc
limit 1)
union all
(select mo.title as results
from Movies mo
inner join MovieRating m
using(movie_id)
where m.created_at>='2020-02-01' and m.created_at<'2020-03-01'
group by mo.movie_id,mo.title
order by avg(m.rating) desc,mo.title asc
limit 1);