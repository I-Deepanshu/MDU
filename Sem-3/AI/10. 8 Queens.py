N = 8 # (size of the chessboard)

def solveNQueens(board, col):
    if col == N:
        print("  ", end="")
        for i in range(1, N+1):
            print(i, end=" ")
        print()
        for i in range(0,len(board)):
            print(i+1, end="")
            for j in range(0,len(board[i])):
                print(board[i][j], end = "")
            print()
        return True
    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = "👑"
            if solveNQueens(board, col + 1):
                return True
            board[i][col] = "⬛"
    return False

def isSafe(board, row, col):
    for x in range(col):
        if board[row][x] == "👑":
            return False
    for x, y in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[x][y] == "👑":
            return False
    for x, y in zip(range(row, N, 1), range(col, -1, -1)):
        if board[x][y] == "👑":
            return False
    return True

board = [["⬛" for x in range(N)] for y in range(N)]
if not solveNQueens(board, 0):
    print("No solution found")