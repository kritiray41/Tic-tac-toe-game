#include <stdio.h>

char board[3][3];
char currentPlayer;

/* Function declarations */
void initializeBoard();
void printBoard();
int checkWin();
int checkDraw();
void switchPlayer();

int main() {
    int row, col;
    int gameOver = 0;

    currentPlayer = 'X';
    initializeBoard();

    printf("🎮 Tic Tac Toe Game (Player vs Player)\n");
    printf("Player 1 = X | Player 2 = O\n\n");

    while (!gameOver) {
        printBoard();

        printf("Player %c, enter row and column (1-3 1-3): ", currentPlayer);
        scanf("%d %d", &row, &col);

        row--; col--;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("❌ Invalid move! Try again.\n\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin()) {
            printBoard();
            printf("🏆 Player %c wins!\n", currentPlayer);
            gameOver = 1;
        } else if (checkDraw()) {
            printBoard();
            printf("🤝 It's a draw!\n");
            gameOver = 1;
        } else {
            switchPlayer();
        }
    }

    return 0;
}

/* Initialize board with empty spaces */
void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

/* Print the game board */
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}

/* Check winning conditions */
int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return 1;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return 1;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return 1;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return 1;

    return 0;
}

/* Check for draw */
int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

/* Switch player */
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
