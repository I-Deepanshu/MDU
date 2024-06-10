def print_board(board):
    for i in range(0, len(board)):
        for j in range(0, len(board[i])):
            print(board[i][j], end = " ")
        print()
        

def check_win(board):
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] != '🔲':
            return True
        if board[0][i] == board[1][i] == board[2][i] != '🔲':
            return True
    if board[0][0] == board[1][1] == board[2][2] != '🔲':
        return True
    if board[0][2] == board[1][1] == board[2][0] != '🔲':
        return True
    return False

def tic_tac_toe():
    board = [['🔲', '🔲', '🔲'], ['🔲', '🔲', '🔲'], ['🔲', '🔲', '🔲']]
    print_board(board)
    emojis={"X":"❌","O":"⭕"}
    player1 = input("Player 1, choose 'X' or 'O': ")
    player2 = 'X' if player1 == 'O' else 'O'
    current_player = player1
    while True:
        move = int(input(f"{current_player}, enter a number between 1-9: "))
        row = (move - 1) // 3
        col = (move - 1) % 3
        if board[row][col] != '🔲':
            print("That spot is already taken. Try again.")
            continue
        board[row][col] = emojis[current_player]
        print_board(board)
        if check_win(board):
            print(f"{current_player} wins!")
            break
        if all([spot != '🔲' for row in board for spot in row]):
            print("It's a tie!")
            break
        current_player = player2 if current_player == player1 else player1

tic_tac_toe()

