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
disp(bias);

% Testing the Hebb Net
disp('Testing Hebb Net:');

for i = 1:size(inputs, 1)
    net_input = dot(weights, inputs(i, :)') + bias;
    output = sign(net_input); % Bipolar output (-1, 1)
    fprintf('Input: [%d %d] -> Output: %d (Target: %d)\n', inputs(i, 1), inputs(i, 2), output, targets(i));
end
