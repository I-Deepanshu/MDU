% Define input-output pairs to be stored in the network
inputs = [1 -1 1; -1 1 -1]; % Each row is an input vector (2x3 matrix)
outputs = [1 0; 0 1]; % Each row is an output vector (2x2 matrix)

% Compute the weight matrix for Hetero-Associative Net
W = outputs' * inputs; % W will be a 2x3 matrix (outputs x inputs)

% Display the weight matrix
disp('Weight matrix for Hetero-Associative Net:');
disp(W);

% Test the network with each input
disp('Testing Hetero-Associative Net:');

for i = 1:size(inputs, 1)
    input = inputs(i, :)'; % Take each input as a column vector (3x1)
    output = sign(W * input); % Output will be a 2x1 vector
    fprintf('Input: [%d %d %d] -> Output: [%d %d]\n', input, output);
end
