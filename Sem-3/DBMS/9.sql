DROP PROCEDURE insertUser;


DROP PROCEDURE <procedure_name>;


CREATE PROCEDURE insertUser (id IN number, name IN varchar)
IS
BEGIN
	INSERT INTO user VALUES(id, name)
END;


CREATE/REPLACE PROCEDURE <procedure_name> (Parameter, Parameter_1…)
IS
	<declaration_section>
BEGIN
	<executable_section>
EXCEPTION
	<exception_section>
END <procedure_name>;


