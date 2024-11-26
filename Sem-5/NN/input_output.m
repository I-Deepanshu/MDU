% Input a number
num = input('Enter a number: ');

% Output the number
disp(['You entered: ', num2str(num)]);

% Input a string
name = input('Enter your name: ', 's'); % 's' for string

% Output the string
fprintf('Hello, %s!\n', name);

% Input a number
radius = input('Enter the radius of the circle: ');

% Calculate the area of a circle
area = pi * radius^2;

% Output the result with formatting
fprintf('The area of the circle with radius %.2f is %.2f\n', radius, area);

% Input multiple numbers
a = input('Enter the first number: ');
b = input('Enter the second number: ');

% Output their sum
fprintf('The sum of %.2f and %.2f is %.2f\n', a, b, a + b);