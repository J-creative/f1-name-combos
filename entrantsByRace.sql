SELECT results.raceId,results.driverId,group_concat(drivers.code),races.year 
from results 
join drivers on results.driverId=drivers.driverId 
join races on results.raceId=races.raceId
group by results.raceId