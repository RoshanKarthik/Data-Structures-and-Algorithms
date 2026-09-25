# Write your MySQL query statement below
select T1.id,
case
    when T1.p_id <=> NULL then 'Root'
    when not exists (
        select 1
        from Tree t2 
        where T1.id = T2.p_id
    ) then 'Leaf'
    else 'Inner'
end as type 
from Tree T1
order by T1.id