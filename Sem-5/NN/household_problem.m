% Generate synthetic data for household prediction (as an example)
num_samples = 1000;

% Input features: Random hours of the day and temperature
hour_of_day = floor(rand(num_samples, 1) * 24);  % Random hours (0 to 23)
temperature = floor(rand(num_samples, 1) * 21) + 15;  % Random temperature (15 to 35 degrees)

% Target: Household energy consumption (example)
energy_consumption = 0.3 * temperature + 0.1 * hour_of_day + randn(num_samples, 1);  % Add some noise

% Save the data into a .mat file for future use
save('household_data.mat', 'hour_of_day', 'temperature', 'energy_consumption');

% Load the data
load('household_data.mat');

% Define parameters
inputs = [hour_of_day, temperature]';  % Inputs are hour of day and temperature (2xN matrix)
targets = energy_consumption';  % Target is energy consumption (1xN vector)

% Neural network parameters
hidden_size = 10;  % Number of neurons in the hidden layer
output_size = 1;   % Number of output neurons (regression)

% Initialize weights and biases with small values
input_size = size(inputs, 1);  % 2 (hour_of_day and temperature)
hidden_weights = randn(hidden_size, input_size) * 0.01;  % Weights for input to hidden layer
hidden_biases = randn(hidden_size, 1) * 0.01;  % Biases for hidden layer
output_weights = randn(output_size, hidden_size) * 0.01;  % Weights for hidden to output layer
output_biases = randn(output_size, 1) * 0.01;  % Biases for output layer

% Define activation functions
sigmoid = @(x) 1 ./ (1 + exp(-max(min(x, 100), -100)));  % Sigmoid activation with clipping
linear = @(x) x;  % Linear activation for output layer

% Gradient descent parameters
learning_rate = 0.001;  % Lower learning rate
epochs = 1000;

% Training loop (Gradient Descent)
for epoch = 1:epochs
    % Forward pass
    hidden_input = hidden_weights * inputs + repmat(hidden_biases, 1, num_samples);  % Replicate biases for each sample
    hidden_output = sigmoid(hidden_input);  % Apply sigmoid activation

    output_input = output_weights * hidden_output + repmat(output_biases, 1, num_samples);  % Replicate biases for each sample
    predicted_output = linear(output_input);  % Apply linear activation

    % Compute the error
    error = targets - predicted_output;  % Error between actual and predicted

    % Backpropagation: Compute gradients and update weights
    % Output layer gradients
    output_error = error;  % Since linear activation, gradient is just the error
    output_gradients = output_error .* ones(size(output_error));  % Gradient for output layer

    % Hidden layer gradients
    hidden_error = output_weights' * output_gradients;  % Propagate error back to hidden layer
    hidden_gradients = hidden_error .* hidden_output .* (1 - hidden_output);  % Sigmoid derivative

    % Update weights and biases using gradient descent
    output_weights = output_weights + learning_rate * output_gradients * hidden_output';
    output_biases = output_biases + learning_rate * sum(output_gradients, 2);

    hidden_weights = hidden_weights + learning_rate * hidden_gradients * inputs';
    hidden_biases = hidden_biases + learning_rate * sum(hidden_gradients, 2);
end

% Test the network
hidden_input = hidden_weights * inputs + repmat(hidden_biases, 1, num_samples);
hidden_output = sigmoid(hidden_input);
output_input = output_weights * hidden_output + repmat(output_biases, 1, num_samples);
predicted_output = linear(output_input);

% Display first 10 predictions in console
disp('First 10 Predicted Energy Consumption:');
disp(predicted_output(1:10));

% Plot actual vs predicted values
figure;
plot(targets, 'r-', 'DisplayName', 'Actual Consumption');
hold on;
plot(predicted_output, 'b-', 'DisplayName', 'Predicted Consumption');
xlabel('Sample Index');
ylabel('Energy Consumption');
title('Actual vs Predicted Household Energy Consumption');
legend;
grid on;
