% Define data for 3D plotting
[X, Y] = meshgrid(-5:0.5:5, -5:0.5:5);
Z = sin(sqrt(X.^2 + Y.^2));

% 3D Surface plot
figure;
surf(X, Y, Z);
title('3D Surface Plot');
xlabel('X-axis');
ylabel('Y-axis');
zlabel('Z-axis');
colormap jet;
colorbar;
