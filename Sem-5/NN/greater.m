num1 = input('Enter the first number: ');
num2 = input('Enter the second number: ');

if num1 < num2
    fprintf('The larger number is %.2f\n', num2);
elseif num1 > num2
    fprintf('The larger number is %.2f\n', num1);
else 
    disp('Both numbers are equal');
end