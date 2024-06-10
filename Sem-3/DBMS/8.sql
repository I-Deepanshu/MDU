DECLARE
	<declaration>
BEGIN
	<exception_section
EXCEPTION
WHEN exception_1 THEN
	<Error handling statements>
WHEN exception_2 THEN
	<Error handling statements>
WHEN Others THEN
	<Error handling statements>
END;



<Exception_Name> EXCEPTION;


RAISE <Exception_Name>; 


DECLARE
	<Exception_Name> EXCEPTION;
BEGIN
	IF condition THEN
		RAISE <exception_name>;
	END IF;
EXCEPTION
	WHEN <exception_name> THEN
		Statements;
END;



DECLARE
	C_ID Customers.id%type,
	C_Name Customers.name%type,
	C_Address Customers.address%type;
BEGIN
	SELECT Name, Address INTO C_Name, C_Address FROM Customers WHERE ID=C_ID;
	dbms_output.put_line(‘Name: ’|| C_Name);
	dbms_output.put_line(‘Address: ‘|| C_Address);
EXCEPTION
	WHEN no_data_found THEN
		dbms_output.put_line(‘No such customer’);
	WHEN others THEN
		dbms_output.put_line(‘Error’);
END;



DECLARE
    -- Exceptions
	Below_salary_range EXCEPTION;
	Above_salary_range EXCEPTION;
    
    -- Variables
	n_salary Employee.salary%type;
	n_min_salary Employee.salary%type;
	n_max_salary Employee.salary%type;

    -- input
	Employee ID Emp_ID;

BEGIN
	SELECT salary, min_salary, max_salary 
	INTO n_salary, n_min_salary, n_max_salary 
	FROM Employee 
	INNER JOIN Jobs ON Jobs.Job_ID = Employee.Job_ID 
	WHERE Employee_ID = Emp_ID;

	IF n_salary < n_min_salary THEN
		RAISE Below_salary_range;

	ELSIF n_salary > n_max_salary THEN
		RAISE Above_salary_range;

	END IF;
	dbms_output.put_line(‘Employee: ‘ || Emp_ID||’ has salary $’||n_salary);

EXCEPTION
	WHEN Below_salary_range THEN
		dbms_output.put_line(‘Employee’|| Emp_ID|| ‘has salary below the salary range’)

	WHEN Above_salary_range THEN
		dbms_output.put_line(‘Employee’|| Emp_ID|| ‘has salary above the salary range’)

	WHEN no_data_found THEN
		dbms_output.put_line(‘Employee’|| Emp_ID || ‘not found’)’
END;
