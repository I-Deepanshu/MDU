CREATE TABLE Parent_Table(
	Column_1 datatype PRIMARY KEY,
	Column_2 datatype,
	…
	Column_N datatype);
 
CREATE TABLE Child_Table(
	Column_1 datatype PRIMARY KEY,
	Column_2 datatype,
	Column_3 datatype,
	FOREIGN KEY (Column_3) REFERENCES Parent_Table(Column_1)
	);



ALTER TABLE Child_Table
	ADD FOREIGN KEY (Column_3) 
	REFERENCES Parent_Table(Column_1);



CREATE TABLE DEPARTMENTS(
    ID INT PRIMARY KEY,
    NAME VARCHAR(50) NOT NULL UNIQUE
);

CREATE TABLE EMP(
    ID INT PRIMARY KEY,
    NAME VARCHAR(50) NOT NULL,
    AGE INT NOT NULL CHECK(AGE > 18),
    DEPT INT,
    TOTAL_SALARY INT NOT NULL,
    FOREIGN KEY (DEPT) REFERENCES DEPARTMENTS(ID)
);