select Manager.name
from Employee
inner join Employee as Manager
on (Employee.managerId=Manager.id)
group by Manager.Id
having count(*)>=5;