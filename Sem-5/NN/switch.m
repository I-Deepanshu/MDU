while true
    % Display menu
    disp('Menu');
    disp('1. Addition');
    disp('2. Subtraction');
    disp('3. Multiplication');
    disp('4. Division');
    disp('5. Exit');

    % User's choice
    choice = input('Enter your choice (1-5): ');

    switch choice
        case 1
            a = input('Enter first number: ');
            b = input('Enter second number: ');
            fprintf('Result: %.2f + %.2f = %.2f\n', a, b, a + b);
        case 2
            a = input('Enter first number: ');
            b = input('Enter second number: ');
            fprintf('Result: %.2f - %.2f = %.2f\n', a, b, a - b);
        case 3
            a = input('Enter first number: ');
            b = input('Enter second number: ');
            fprintf('Result: %.2f * %.2f = %.2f\n', a, b, a * b);
        case 4
            a = input('Enter first number: ');
            b = input('Enter second number: ');

            if b == 0
                disp('Error: Division by zero!');
            else
                fprintf('Result: %.2f / %.2f = %.2f\n', a, b, a / b);
            end

        case 5
            disp('Exiting program.');
            break;
        otherwise
            disp('Invalid choice! Please select again.');
    end

end
