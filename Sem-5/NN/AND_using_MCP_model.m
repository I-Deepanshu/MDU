% Define weights and threshold
w1 = 1;
w2 = 1;
threshold = 2;

% Define input combinations for the AND function
inputs = [0 0; 0 1; 1 0; 1 1];
output = zeros(4, 1); % Initialize output array

% Calculate the output for each input combination
for i = 1:size(inputs, 1)
    x1 = inputs(i, 1);
    x2 = inputs(i, 2);
    
    % Compute the net input
    net_input = (w1 * x1) + (w2 * x2);
    
    % Determine output based on threshold
    if net_input >= threshold
        output(i) = 1;
    else
        output(i) = 0;
    end
end

% Display results
disp('AND Function using MCP Model:');
disp('     x1    x2    y');
disp([inputs, output]);
