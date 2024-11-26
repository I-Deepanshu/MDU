% Main script to call the swap function
a = input('Enter first number: ');
b = input('Enter second number: ');

fprintf('Before swapping: a = %.2f, b = %.2f\n', a, b);

% Call swap function
[a, b] = swap(a, b);

fprintf('After swapping: a = %.2f, b = %.2f\n', a, b);

% Swap function definition
function [x, y] = swap(x, y)
    % Temporary variable for swapping
    temp = x;
    x = y;
    y = temp;
end
