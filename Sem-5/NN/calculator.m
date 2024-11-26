while true
    % Input two numbers
    num1 = input('Enter the first number: ');
    num2 = input('Enter the second number: ');

    % Input operator with validation
    valid_operators = {'+', '-', '*', '/', '^'};
    operator = input('Enter an operator (+, -, *, /, ^): ', 's');
    
    % ~ is the logical NOT operator
    % ismember checks if the operator is in the valid_operators list
    while ~ismember(operator, valid_operators)
        disp('Invalid operator! Please enter one of +, -, *, /, ^.');
        operator = input('Enter an operator (+, -, *, /, ^): ', 's');
    end

    % Perform the calculation based on the operator
    switch operator
        case '+'
            result = num1 + num2;
        case '-'
            result = num1 - num2;
        case '*'
            result = num1 * num2;
        case '/'
            if num2 == 0
                disp('Error: Division by zero is not allowed!');
                continue;
            end
            result = num1 / num2;
        case '^'
            result = num1 ^ num2;
    end

    % Output the result
    fprintf('The result of %.2f %s %.2f = %.2f\n', num1, operator, num2, result);
    
    % Ask the user if they want to perform another calculation
    choice = input('Do you want to perform another calculation? (y/n): ', 's');
    if choice == 'n'
        disp('Exiting calculator.');
        break;
    end
end