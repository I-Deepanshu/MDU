% Define the vector to be stored
vector = [1; -1; 1; -1];

% Compute the weight matrix
W = vector * vector';

% Display the weight matrix
disp('Weight matrix for Auto-Associative Net:');
disp(W);

% Test the network with the input
input = vector; % Using the same vector as input
output = sign(W * input); % Retrieve stored vector

% Display the result
disp('Output after testing with input:');
disp(output);
