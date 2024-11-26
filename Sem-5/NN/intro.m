% What is MATLAB?
% MATLAB (Matrix Laboratory) is a high-level programming language and environment developed by MathWorks. It’s designed for numerical computing, making it ideal for tasks such as data analysis, algorithm development, and scientific computing. It also has extensive support for visualization, allowing users to create plots and graphs easily.

% What is MATLAB used for?
% MATLAB is widely used in various fields, including:
% - Engineering: Signal processing, control systems, robotics.
% - Data Science: Data visualization, machine learning.
% - Research: Mathematical modeling, simulation, numerical analysis.
% - Education: Teaching mathematics, physics, and engineering concepts.

% How to Install MATLAB
% 1.	Go to MathWorks Website: https://www.mathworks.com
% 2.	Create an Account: Sign up if you don't have an account.
% 3.	Download the Installer: Go to the "Download" section and download MATLAB for your OS.
% 4.	Run the Installer: Launch the installer and follow the on-screen instructions.
% 5.	Activate MATLAB: After installation, you’ll need to activate MATLAB using your MathWorks account or a license key.

% Basic Syntax in MATLAB

% 1. Variables
% You don’t need to declare variable types in MATLAB. You can directly assign values to variables.

% Example of a variable
x = 10; % assigns 10 to x
y = 5;  % assigns 5 to y

% 2. Input/Output
% You can use the input function to get user input and disp or fprintf for output.

% Input from the user
name = input('Enter your name: ', 's'); % 's' denotes string input

% Output
disp(['Hello, ' name]); % displays 'Hello, [name]'

% 3. Basic Mathematical Operations
% MATLAB supports standard arithmetic operations, and you can perform matrix manipulations directly.
% Arithmetic operations
a = 5;
b = 3;
sum = a + b;   % Addition
diff = a - b;  % Subtraction
prod = a * b;  % Multiplication
quot = a / b;  % Division

% 4. Plotting
% You can create basic plots easily with built-in functions.
% Simple plot
x = 0:0.1:10; % Create a range from 0 to 10 with step size 0.1
y = sin(x);   % Calculate sine of each value in x
plot(x, y);   % Plot y = sin(x)