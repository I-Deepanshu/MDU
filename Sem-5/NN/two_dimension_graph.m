% Define data for 2D plotting
x = linspace(0, 2 * pi, 100);
y1 = sin(x);
y2 = cos(x);

% Plot sine and cosine functions
figure;
plot(x, y1, '-r', 'LineWidth', 1.5);
hold on;
plot(x, y2, '-b', 'LineWidth', 1.5);
title('2D Plot of Sine and Cosine');
xlabel('x');
ylabel('y');
legend('sin(x)', 'cos(x)');
grid on;
