% Define data
x = linspace(0, 2 * pi, 100);
y1 = sin(x);
y2 = cos(x);
y3 = x.^2;
y4 = exp(-x);

% Create a 2x2 grid of subplots
figure;

% First subplot: Sine function
subplot(2, 2, 1);
plot(x, y1, 'r');
title('Sine Function');
xlabel('x');
ylabel('sin(x)');

% Second subplot: Cosine function
subplot(2, 2, 2);
plot(x, y2, 'b');
title('Cosine Function');
xlabel('x');
ylabel('cos(x)');

% Third subplot: Parabola
subplot(2, 2, 3);
plot(x, y3, 'g');
title('Parabolic Function');
xlabel('x');
ylabel('x^2');

% Fourth subplot: Exponential decay
subplot(2, 2, 4);
plot(x, y4, 'm');
title('Exponential Decay');
xlabel('x');
ylabel('exp(-x)');

% Adjust spacing
sgtitle('Subplot Example');
