% MATLAB offers a powerful toolbox called the Neural Network Toolbox (now part of the Deep Learning Toolbox), which simplifies the creation, training, and evaluation of neural networks. This toolbox includes prebuilt functions for various network types, training algorithms, and visualization tools.

% Here’s a guide to help you explore these tools:

% Key Tools in MATLAB’s Neural Network Toolbox
% 1. nntool:This command opens a graphical interface for creating and training neural networks.
% - To start, type nntool in the MATLAB command window.
% - You can use this GUI to import data, define network architectures, train networks, and evaluate performance.

% 2. Deep Network Designer:A more advanced tool for designing deep neural networks.
% - Type deepNetworkDesigner in the command window.
% - You can drag and drop layers to design a network, set layer properties, and train it directly.

% 3. Predefined Functions:
% - feedforwardnet:For creating feedforward neural networks.
% - patternnet:For classification problems.
% - fitnet:For regression tasks.
% - trainNetwork:For training networks with custom data and parameters.

% Generate synthetic data for XOR-like problem (Binary Classification)
num_samples = 1000;

% Input features: random binary inputs (0 or 1)
inputs = round(rand(num_samples, 2));

% Target: XOR operation (1 if the two inputs are different, 0 otherwise)
target = xor(inputs(:, 1), inputs(:, 2))';

% Save the data into a .mat file for future use
save('xor_data.mat', 'inputs', 'target');

% Define parameters
input_size = size(inputs, 2); % Number of input features
hidden_size = 3; % Number of neurons in the hidden layer
output_size = 1; % One output neuron (binary classification)
learning_rate = 0.1; % Learning rate
epochs = 1000; % Number of epochs (iterations)

% Initialize weights randomly
W_input_hidden = rand(hidden_size, input_size); % Weights between input and hidden layer
W_hidden_output = rand(output_size, hidden_size); % Weights between hidden and output layer

% Sigmoid activation function
sigmoid = @(x) 1 ./ (1 + exp(-x)); % Sigmoid function
sigmoid_derivative = @(x) x .* (1 - x); % Derivative of sigmoid

% Training the network using backpropagation
for epoch = 1:epochs
    % Forward pass: Compute hidden layer outputs
    hidden_input = W_input_hidden * inputs'; % Weighted sum of inputs to hidden layer
    hidden_output = sigmoid(hidden_input); % Apply sigmoid activation function

    % Compute final output
    final_input = W_hidden_output * hidden_output; % Weighted sum to output layer
    output = sigmoid(final_input); % Apply sigmoid for output layer

    % Compute error (difference between target and predicted output)
    error = target - output;

    % Backpropagation
    output_delta = error .* sigmoid_derivative(output); % Error term for output layer
    hidden_delta = (W_hidden_output' * output_delta) .* sigmoid_derivative(hidden_output); % Error term for hidden layer

    % Update weights using gradient descent
    W_hidden_output = W_hidden_output + learning_rate * output_delta * hidden_output';
    W_input_hidden = W_input_hidden + learning_rate * hidden_delta * inputs;
end

% Display trained network's weights in console
disp('Trained Weights:');
disp('Weights from input to hidden layer:');
disp(W_input_hidden);
disp('Weights from hidden to output layer:');
disp(W_hidden_output);

% Test the network (predict with the same data used for training)
hidden_input = W_input_hidden * inputs';
hidden_output = sigmoid(hidden_input);
final_input = W_hidden_output * hidden_output;
predicted_output = sigmoid(final_input);

% Display first 10 predictions to give an idea of how well the network learned
disp('First 10 Predictions:');
disp(predicted_output(:, 1:10));

% Plot the performance (error vs. epoch)
figure;
plot(1:epochs, error);
xlabel('Epochs');
ylabel('Error');
title('Training Error vs Epochs');
grid on;

% Plot output vs target for the first 10 samples (for visual inspection)
figure;
plot(target(1:10), 'ro-', 'MarkerFaceColor', 'r');
hold on;
plot(predicted_output(1:10), 'bo-', 'MarkerFaceColor', 'b');
legend('Target', 'Predicted');
xlabel('Sample Index');
ylabel('Output');
title('Target vs Predicted Output (First 10 Samples)');
grid on;
