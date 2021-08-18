SELECT
	doctors.name, ROUND(SUM((attendances.hours*150)*(1+work_shifts.bonus/100)),1) as salary
FROM
	doctors
INNER JOIN attendances ON attendances.id_doctor=doctors.id
INNER JOIN work_shifts ON attendances.id_work_shift=work_shifts.id
GROUP BY
	doctors.name
ORDER BY
	salary DESC