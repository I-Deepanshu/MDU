% Define input patterns (bipolar) and target values
inputs = [1 1; 1 -1; -1 1; -1 -1]; % 2D bipolar inputs
targets = [1; -1; -1; -1]; % Target values for each input pattern

% Initialize weights and bias
weights = [0; 0]; % 2D weight vector
bias = 0;

% Hebbian learning rule
for i = 1:size(inputs, 1)
    weights = weights + inputs(i, :)' * targets(i);
    bias = bias + targets(i);
end

% Display results
disp('Weights after Hebbian learning:');
disp(weights);
disp('Bias after Hebbian learning:');
disp(bias);% Define bipolar input patterns and target values for AND
inputs = [-1 -1; -1 1; 1 -1; 1 1];
targets = [-1; -1; -1; 1]; % Bipolar targets

% Initialize weights, bias, and learning rate
weights = [0; 0];
bias = 0;
learning_rate = 0.1;
epochs = 10;

% Perceptron training
for epoch = 1:epochs
    for i = 1:size(inputs, 1)
        % Calculate the output
        net_input = dot(weights, inputs(i, :)') + bias;
        output = sign(net_input);
        
        % Update weights and bias if output does not match target
        error = targets(i) - output;
        weights = weights + learning_rate * error * inputs(i, :)';
        bias = bias + learning_rate * error;
    end
end

% Display trained weights and bias
disp('Trained weights:');
disp(weights);
disp('Trained bias:');
disp(bias);

% Testing the Perceptron for AND
disp('Testing Perceptron for AND:');
for i = 1:size(inputs, 1)
    net_input = dot(weights, inputs(i, :)') + bias;
    output = sign(net_input);
    fprintf('Input: [%d %d] -> Output: %d (Target: %d)\n', inputs(i, 1), inputs(i, 2), output, targets(i));
end


% Testing the Hebb Net
disp('Testing Hebb Net:');
for i = 1:size(inputs, 1)
    net_input = dot(weights, inputs(i, :)') + bias;
    output = sign(net_input); % Bipolar output (-1, 1)
    fprintf('Input: [%d %d] -> Output: %d (Target: %d)\n', inputs(i, 1), inputs(i, 2), output, targets(i));
end
