% Hebb Net to classify two dimensional input patterns
clear;
clc;

% Input Patterns
E = [1 1 1 1 1 -1 -1 -1 -1 -1 1 1 1 1 1 -1 -1 -1 -1 -1];
F = [1 1 -1 -1 -1 1 1 -1 -1 -1 1 1 -1 -1 -1 1 1 -1 -1 -1];

x(1:20) = E;
x(21:40) = F;
w(1:20) = 0;
t = [-1 1];
b = 0;

for i = 1:2
    w = w + x(1,1:20) * t(1);
    b = b + t(1);
end

disp('Weight matrix');
disp(w);
disp('Bias');
disp(b);

