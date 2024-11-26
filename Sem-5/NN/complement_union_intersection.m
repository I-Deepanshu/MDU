% Define sets A and B
A = [1, 2, 3, 4, 5];
B = [4, 5, 6, 7, 8];

% Complement of A relative to universal set U
U = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];  % Example universal set
complement_A = setdiff(U, A);

% Union of A and B
union_AB = union(A, B);

% Intersection of A and B
intersection_AB = intersect(A, B);

% Display results
disp('Complement of A:');
disp(complement_A);
disp('Union of A and B:');
disp(union_AB);
disp('Intersection of A and B:');
disp(intersection_AB);