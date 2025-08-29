SELECT en.unique_id, e.name
FROM Employees AS e
LEFT JOIN EmployeeUNI AS en
ON e.id = en.id;
