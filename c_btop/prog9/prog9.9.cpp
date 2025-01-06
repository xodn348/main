/* Program 9.9 REVERSI An Othello type game */
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Game constants
const int SIZE = 6;           // Board size - must be even
const char comp_c = '@';      // Computer's counter (black)
const char player_c = 'O';    // Player's counter (white)

/* Function prototypes */
void display(char board[][SIZE]);  // Function to display game board
int valid_moves(char board[][SIZE], bool moves[][SIZE], char player);
void make_move(char board[][SIZE], int row, int col, char player);
void computer_move(char board[][SIZE], bool moves[][SIZE], char player);
int best_move(char board[][SIZE], bool moves[][SIZE], char player);
int get_score(char board[][SIZE], char player);


int main(void)
{
    char board[SIZE][SIZE] = { 0 };    // Game board array
    bool moves[SIZE][SIZE] = { false }; // Array to store valid moves
    int row = 0;                       // Row index
    int col = 0;                       // Column index
    int no_of_games = 0;
    int no_of_moves = 0;
    int invalid_moves = 0;
    int comp_score = 0;
    int user_score = 0;
    char y = 0;
    int x = 0;
    char again;                        // Add missing variable declaration

    /* Player indicator: true for player and false for computer*/
    bool next_player = true;
    
    // Display game instructions
    printf("\nREVERSI\n\n");
    printf("You can go first on the first gaem, then we will take turns.\n");
    printf(" You will be white - (%c)\n I will be black   - (%c).\n",
                                                    player_c, comp_c);
    printf("Select a square for your move by typing a digit for the row\n"
                                "and a letter for the column with no spaces between.\n");
    printf("\nGood luck!   Press Enter to start.\n");
    scanf("%c", &again);               // Wait for Enter key

    /* The main game loop*/
    do
    {
        /* On even games the player starts */
        /* on odd games the computer starts */
        next_player = true;    // Start with player's turn
        no_of_moves = 4;

        /* Blank all the board squares*/
        for(row = 0; row < SIZE; row++)
            for(col = 0; col < SIZE; col++)
                board[row][col] = ' ';

        /* Place initial counters */
        int mid = SIZE/2;                  // Calculate center of board
        // Place initial four counters in center squares
        board[SIZE/2 - 1][SIZE/2 - 1] = board[SIZE/2][SIZE/2] = 'O';     // White counters
        board[SIZE/2 - 1][SIZE/2] = board[SIZE/2][SIZE/2 - 1] = '@';       // Black counters
        
        /* The game play loop*/
        do
        {
            display(board);
            if(next_player)
            {
                /* It is the player's turn*/
                printf("Checking valid moves for player...\n");
                if(valid_moves(board, moves, player_c))
                {
                    /* Read player moves until a valid move is entered*/
                    for(;;)
                    {
                        printf("Please enter your move (row letter): ");
                        scanf(" %d%c", &x, &y);
                        y = tolower(y) - 'a';
                        x--;
                        if(x >= 0 && y >= 0 && x < SIZE && y < SIZE && moves[x][y])
                        {
                            make_move(board, x, y, player_c);
                            no_of_moves++;
                            next_player = !next_player;  // Toggle player after move
                            break;
                        }
                        else
                        {
                            printf("Not a valid move - try again\n");
                        }
                    }
                }
                else
                {
                    if(++invalid_moves < 2)
                    {
                        printf("\nYou have to pass, press return");
                        scanf("%c", &again);
                        next_player = !next_player;  // Toggle player after pass
                    }
                    else
                    {
                        printf("Neither of us can go, so the game is over.\n");
                    }
                }
            }
            else
            {   /* It is the computer's turn*/
                if(valid_moves(board, moves, comp_c))
                {
                    invalid_moves = 0;
                    computer_move(board, moves, comp_c);
                    no_of_moves++;
                    next_player = !next_player;  // Toggle player after computer move
                }
                else
                {
                    if(++invalid_moves<2)
                    {
                        printf("\nI have to pass, your go\n");
                        next_player = !next_player;  // Toggle player after pass
                    }
                    else
                        printf("Neither of us can go, so the game is over.\n");
                }
            }
        } while (no_of_moves < SIZE*SIZE && invalid_moves<2);

        /* Game isn over*/
        display(board);

        /* Get final scores and display them */
        comp_score = user_score = 0;
        for(row = 0; row < SIZE; row++)
            for(col = 0; col < SIZE; col++)
            {
                comp_score += board[row][col] == comp_c;
                user_score += board[row][col] == player_c;
            }
        printf("The final score is:\n");
        printf("Computer %d\nUser %d\n\n", comp_score, user_score);

        printf("Do tou want to play again (y/n): ");
        scanf(" %c", &again);
    } while(tolower(again) == 'y');

    printf("Goodbye\n");
    return 0;
} 

/* Display function implementation */
void display(char board[][SIZE])
{
    char col_label = 'a';                    // Starting column label

    // Display column labels (a, b, c, etc.)
    printf("\n ");                           /* Start top line */
    for(int col = 0; col < SIZE ; col++)
        printf("   %c", col_label+col);     /* Display the top line */
    printf("\n");                           /* End top line */

    // Display each row of the board
    for(int row = 0; row < SIZE; row++)
    {
        // Display top border of current row
        printf("  +");
        for(int col = 0; col<SIZE; col++)
            printf("---+");
        printf("\n%2d|", row +1);               // Display row number

        // Display counters in current row
        for(int col = 0; col<SIZE; col++)
            printf(" %c |", board[row][col]);   /* Display counters in row */
        printf("\n");
    }

    // Display bottom border of the board
    printf("  +");
    for(int col = 0 ; col < SIZE; col++)
        printf("---+");
    printf("\n");
}


/***********************************************
* Calculates which squares are valid moves *
* for player. Valid moves are recorded in the *
* moves array - true indicates a valid move, *
* false indicates an invalid move. *
* First parameter is the board array *
* Second parameter is the moves array *
* Third parameter identifies the player *
* to make the move. *
* Returns valid move count. *
**********************************************/

int valid_moves(char board[][SIZE], bool moves[][SIZE], char player)
{
    // Add debug print
    printf("Checking moves for player: %c\n", player);  // Debug line

    int rowdelta = 0;
    int coldelta = 0;
    int x = 0;
    int y = 0;
    int no_of_moves = 0;

    /* Set the opponent's counter */
    char opponent = (player == player_c) ? comp_c : player_c;

    /* Check all squares on the board */
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col < SIZE; col++)
            moves[row][col] = false;    // Reset all moves to false
    
    /* Find squares for valid moves*/
    /* A valid move must be on a blank square and must enclose*/
    /* at least one opponent square between two player squares*/
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col < SIZE; col++)
        {
            if(board[row][col] != ' ')
            continue;

            /* Check all eight directions for a valid move */
            /* foe the opponent's counter */
            for(rowdelta = -1; rowdelta <= 1; rowdelta++)
                for(coldelta = -1; coldelta <= 1; coldelta++)
                {
                /* Don't check outside the array, or the current square*/
                if(row + rowdelta < 0 || row + rowdelta >= SIZE ||
                   col + coldelta < 0 || col + coldelta >= SIZE ||
                   (rowdelta == 0 && coldelta ==0))
                   continue;
                
                /* Now check the square */
                if(board[row + rowdelta][col + coldelta] == opponent)
                {
                    /* If we find the opponent's counter, move in the delta direction */
                    /* over opponent counters searching for a player counter */
                    x = row + rowdelta;
                    y = col + coldelta;

                    /* Look for a player square in the delta direction */
                    for(;;)
                    {
                        x += rowdelta;
                        y += coldelta;

                        /* If we move outside the array, give up */
                        if(x < 0 || x > SIZE || y < 0 || y >= SIZE)
                        break;

                        /* If we find a blank square, give up*/
                        if(board[x][y] == ' ')
                        break;

                        /* If we find a player square, we have a valid move */
                        if(board[x][y] == player)
                        {
                            moves[row][col] = true;
                            no_of_moves++;
                            break;
                        }
                    }
                }
                }
        }
    // Add debug print
    printf("Found %d valid moves\n", no_of_moves);  // Debug line
    
    return no_of_moves;
}

/********************************************************************
* Makes a move. This places the counter on a square and reverses *
* all the opponent's counters affected by the move. *
* First parameter is the board array. *
* Second and third parameters are the row and column indices. *
* Fourth parameter identifies the player. *
********************************************************************/

void make_move(char board[][SIZE], int row, int col, char player)
{
    int rowdelta = 0;
    int coldelta = 0;
    int x = 0;
    int y = 0;

    /* Identify opponent*/
    char opponent = (player == player_c) ? comp_c : player_c;

    /* Place the player's counter on the board*/
    board[row][col] = player;

    /* Check all eight directions for opponent's counters*/
    /* for the opponents counters*/
    for(rowdelta = -1; rowdelta <= 1; rowdelta++)
        for(coldelta = -1; coldelta <= 1; coldelta++)
        {
            /* Don't check outside the array, or the current square*/
            if(row + rowdelta < 0 || row + rowdelta >= SIZE ||
               col + coldelta < 0 || col + coldelta >= SIZE ||
               (rowdelta == 0 && coldelta == 0))
               continue;
        
            /* Now check the square */
            if(board[row + rowdelta][col + coldelta] == opponent)
            {
            /* If we find the opponent's counter, search in the delta direction */
            /* for a player counter */
            x = row + rowdelta;
            y = col + coldelta;

            /* Look for a player square in the delta direction */
            for(;;)
            {
                x += rowdelta;
                y += coldelta;

                /* If we move outside the array, give up */
                if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
                    break;
                
                /* If we find a blank square, give up */
                if(board[x][y] == ' ')
                    break;

                /* If we find a player square, reverse the opponent's counters */
                if(board[x][y] == player)
                {
                    while(board[x-=rowdelta][y-=coldelta] == opponent)
                        board[x][y] = player;
                    break;
                }
            }
            }
        }
}

/*******************************************************************
* Calculates the score for the current board position for the *
* player. player counters score +1, opponent counters score -1 *
* First parameter is the board array *
* Second parameter identifies the player *
* Return value is the score. *
*******************************************************************/
int get_score(char board[][SIZE], char player)
{
    int score = 0; /* Score for current position */
    
    /* Identify opponent */
    char opponent = (player == player_c) ? comp_c : player_c;
    
    /* Check all board squares */
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col < SIZE; col++)
        {
            score -= board[row][col] == opponent; /* Decrement for opponent */
            score += board[row][col] == player; /* Increment for player */
        }
    return score;
}

/*******************************************************************
* Calculates the score for the best move out of the valid moves *
* for player in the current position. *
* First parameter is the board array *
* Second parameter is the moves array defining valid moves. *
* Third parameter identifies the player *
* The score for the best move is returned *
*******************************************************************/
int best_move(char board[][SIZE], bool moves[][SIZE], char player)
{
    /* Identify opponent */
    char opponent = (player == player_c) ? comp_c : player_c;
    char new_board[SIZE][SIZE] = { 0 }; /* Local copy of board */
    int score = 0; /* Best score */
    int new_score = 0; /* Score for current move */
    /* Check all valid moves to find the best */
    for(int row = 0 ; row<SIZE ; row++)
    for(int col = 0 ; col<SIZE ; col++)
        {
            if(!moves[row][col]) /* Not a valid move? */
                continue; /* Go to the next */
            /* Copy the board */
            memcpy(new_board, board, sizeof(new_board));

            /* Make the move */
            make_move(new_board, row, col, player);
            
            /* Calculate the score for the move */
            new_score = get_score(new_board, player);
            
            /* If this is the best score so far, record it */
            if(score < new_score)
                score = new_score;
        }
    return score;
}

/*******************************************************************
* Finds the best move for the computer. This is the move for *
* which the opponent's best possible move score is a minimum. *
* First parameter is the board array. *
* Second parameter is the moves array containing valid moves. *
* Third parameter identifies the computer. *
*******************************************************************/
void computer_move(char board[][SIZE], bool moves[][SIZE], char player)
{
    int best_row = 0; /* Best row index */
    int best_col = 0; /* Best column index */
    int new_score = 0; /* Score for current move */
    int score = 100; /* Minimum opponent score */
    char temp_board[SIZE][SIZE]; /* Local copy of board */
    bool temp_moves[SIZE][SIZE]; /* Local valid moves array */
    
    /* Identify opponent */
    char opponent = (player == player_c) ? comp_c : player_c;
    /* Go through all valid moves */
    for(int row = 0; row < SIZE; row++)
        for(int col = 0; col < SIZE; col++)
        {
            if( !moves[row][col] )
                continue;
            
            /* First make copies of the board array */
            memcpy(temp_board, board, sizeof(temp_board));
            
            /* Now make this move on the temporary board */
            make_move(temp_board, row, col, player);
            
            /* find valid moves for the opponent after this move */
            valid_moves(temp_board, temp_moves, opponent);
            
            /* Now find the score for the opponent's best move */
            new_score = best_move(temp_board, temp_moves, opponent);
            
            if(new_score<score) /* Is it worse? */
            { /* Yes, so save this move */
                score = new_score; /* Record new lowest opponent score */
                best_row = row; /* Record best move row */
                best_col = col; /* and column */
            }
        }
    /* Make the best move */
    make_move(board, best_row, best_col, player);
}
    