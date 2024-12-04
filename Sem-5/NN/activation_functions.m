% Define x-axis range for plotting
x = linspace(-5, 5, 100);

% Calculate each activation function
y_sin = sin(x);
y_cos = cos(x);
y_tanh = tanh(x);
y_signum = sign(x); % Signum function
y_sigmoid = 1 ./ (1 + exp(-x)); % Sigmoid function
y_threshold = double(x >= 0); % Threshold function (step function)
y_identity = x; % Identity function

% Create figure for subplots
figure;
sgtitle('Activation Functions'); % Use sgtitle instead of suptitle

% Plot sin(x)
subplot(3, 3, 1);
plot(x, y_sin, 'r', 'LineWidth', 1.5);
title('sin(x)');
xlabel('x');
ylabel('y');
grid on;

% Plot cos(x)
subplot(3, 3, 2);
plot(x, y_cos, 'b', 'LineWidth', 1.5);
title('cos(x)');
xlabel('x');
ylabel('y');
grid on;

% Plot tanh(x)
subplot(3, 3, 3);
plot(x, y_tanh, 'g', 'LineWidth', 1.5);
title('tanh(x)');
xlabel('x');
ylabel('y');
grid on;

% Plot signum(x)
subplot(3, 3, 4);
plot(x, y_signum, 'm', 'LineWidth', 1.5);
title('signum(x)');
xlabel('x');
ylabel('y');
grid on;

% Plot sigmoid(x)
subplot(3, 3, 5);
plot(x, y_sigmoid, 'c', 'LineWidth', 1.5);
title('sigmoid(x)');
xlabel('x');
ylabel('y');
grid on;

% Plot threshold function
subplot(3, 3, 6);
plot(x, y_threshold, 'k', 'LineWidth', 1.5);
title('threshold(x)');
xlabel('x');
ylabel('y');
ylim([-0.2, 1.2]);
grid on;

% Plot identity function
subplot(3, 3, 7);
plot(x, y_identity, 'y', 'LineWidth', 1.5);
title('identity(x)');
xlabel('x');
ylabel('y');
grid on;

% Adjust subplot layout for better spacing
set(gcf, 'Position', [100, 100, 800, 600]); % Optional: Adjust figure size
