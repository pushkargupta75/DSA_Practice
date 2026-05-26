# Write your MySQL query statement below
select s.product_id,s.year as first_year,s.quantity,s.price 
from Sales s
join(select product_id,min(year) as firstyear from Sales group by 1) as t
using(product_id) where s.year=t.firstyear;