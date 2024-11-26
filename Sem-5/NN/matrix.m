% Define matrices A and B
A = [1, 2; 3, 4];
B = [5, 6; 7, 8];

% Display matrices
disp('Matrix A:');
disp(A);
disp('Matrix B:');
disp(B);

% Matrix Transpose
disp('Transpose of A:');
disp(A');

% Matrix Addition
if size(A) == size(B)
    sum_AB = A + B;
    disp('Sum of A and B:');
    disp(sum_AB);
else
    disp('Matrices must be of the same size for addition.');
end

% Matrix Multiplication
if size(A, 2) == size(B, 1)
    product_AB = A * B;
    disp('Product of A and B:');
    disp(product_AB);
else
    disp('Matrix dimensions are not compatible for multiplication.');
end

% Matrix Inverse (only for square matrices)
if det(A) ~= 0
    inverse_A = inv(A);
    disp('Inverse of A:');
    disp(inverse_A);
else
    disp('Matrix A is singular and cannot be inverted.');
end
