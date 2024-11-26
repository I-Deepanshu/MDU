% Number of rows for the triangle
rows = input('Enter the number of rows: ');

for i = 1:rows
    % Print spaces for alignment
    for j = 1:(rows - i)
        fprintf(' ');
    end
    % Print asterisks for the triangle
    for k = 1:(2 * i - 1)
        fprintf('*');
    end
    fprintf('\n'); % Move to next line after each row
end
