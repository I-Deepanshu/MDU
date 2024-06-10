DECLARE 
	<variable declaration>;
BEGIN
	IF(condition) THEN
		<executable statments>;
	ELSIF(condition) THEN
		<executable statments>;
	ELSE 
		<executable statments>;
	END IF;
END;

DECLARE 
	<variable declaration>;
BEGIN
	LOOP 
		<executable statments>;
	END LOOP;
	WHILE (condition)
		<executable statments>;
	END LOOP;
END;


DELCALRE	
	a number;
	b number;
	c number;
BEGIN
	a: =&a;
	b: =&b;
	c: = a + b;
	dbms_output.put_line(‘sum of’ ||a|| ’and’ ||b|| ‘ is’ ||c);
END;


DECLARE
	a number;
	b number;
	c number;
BEGIN
	a:=&a;
	b:=&b;
	c:=&c;
	IF(a > b) and (a > c) THEN
		dbms_output.put_lines(‘A is maximum’);
	ELSIF (b > a) and (b > c) THEN
		dbms_output.put_lines(‘B is maximum’);
	ELSE
		dbms_output.put_lines(‘C is maximum’);
	END IF;
END;


DECLARE
    n number;
    sum1 number DEFAULT 0;
    endvalue number;
BEGIN
    endvalue:=&endvalue;
    n:=1;
    FOR n IN 1 ..endvalue
    	LOOP
    	IF mod(n, 2) == 1
    		THEN
    		sum1:=sum1+n
    	END IF;
    	END LOOP;
dbms_output.put_line(‘sum=’||sum1);
END;

