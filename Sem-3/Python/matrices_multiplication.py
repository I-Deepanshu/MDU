def matrix_multiplication(A, B):
    rowA, colA = len(A), len(A[0])
    rowB, colB = len(B), len(B[0])
    if colA != rowB:
        print("Matrices can't be multiplied")
        exit(0)
    C = [[0] * colB for _ in range(rowA)]
    for i in range(rowA):
        for j in range(colB):
            for k in range(colA):
                C[i][j] += A[i][k] * B[k][j]
    return C

# Example usage
rowA = int(input("Enter the number of rows for matrix A: "))
colA = int(input("Enter the number of columns for matrix A: "))
A = []
for i in range(rowA):
    row = []
    for j in range(colA):
        row.append(int(input(f"A[{i+1}][{j+1}] = ")))
    A.append(row)

rowB = colA
colB = rowA
B = []
for i in range(rowB):
    row = []
    for j in range(colB):
        row.append(int(input(f"B[{i+1}][{j+1}] = ")))
    B.append(row)

C = matrix_multiplication(A, B)
print(C)
