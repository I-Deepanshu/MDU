CREATE TRIGGER totalSalary 
    BEFORE INSERT ON Employee 
    FOR EACH ROW 
    SET Employee.TOTAL_SALARY = Employee.BASE_SALARY + Employee.BONUS;

CREATE TRIGGER <trigger_name> <before/after> 
	<insert/update/delete> ON <table_name> <for_each_row>
	<TRIGGER_BODY>
