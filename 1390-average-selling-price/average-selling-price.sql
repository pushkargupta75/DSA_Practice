# Write your MySQL query statement below
select P.product_id,round(ifnull(sum(P.price*U.units)/sum(U.units),0),2) as average_price
from Prices P
left join UnitsSold U
on P.product_id=U.product_id
and U.purchase_date between P.start_date and P.end_date
group by P.product_id; 