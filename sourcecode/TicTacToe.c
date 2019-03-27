#include <stdio.h>


///-------------------------------------------------------------------
///   Program:        TicTacToe (C Program)
///
///   Description:    This is the main source code for the coursework
///                   C tic tac toe program                   
///                   
///   Author:         Francesco Fico (40404272)     Date: 03/2019
///-------------------------------------------------------------------




//2 dimensional array declared
char board[3][3];

//win condition char return declared
char winCondition(void);

//functions declaration
void createBoard(void);
void displayBoard(void);
void getPlayer1(void);
void getPlayer2(void);
void autoMove(void);
void getAI(void);

//main application
int main(void)
{
    //string to store the win condition declared and set up as blank space
    char win = ' ';

    //printing game title
    printf("\n");
    printf("TIC TAC TOE\n");
    printf("\n");


    //initialise the array
    createBoard();

    //actual game starts
    do
    {
        //print the board on the screen
        displayBoard();
        printf("\n");

        //get the player move
        getPlayer1();
        printf("\n");

        //check if there are win condition
        win = winCondition();

        //if the win char changes from blank someone has won the game
        if (win != ' ')
            break;

        //re-print the board on the screen    
        displayBoard();
        printf("\n");
        printf("AI Moves \n");

        //the computer prints the nought
        autoMove();

        //below the command to play with the euristic AI
        //getAI();

        //below the command to play with a second human player
        //getPlayer2();
        printf("\n");

        //re-check for any winning conditions
        win = winCondition();

      //until win condition does not change stay in the loop  
    } while (win == ' ');

    //if the condition string change to an X player 1 wins
    if (win == 'X')
        printf("Player 1 wins!\n");

    //otherwise player 2 wins    
    else
        printf("Player 2 wins!\n");

    //print the board again
    displayBoard();

    return 0;
}

//function that initialise the 2 dimensional array
void createBoard(void)
{

    //for loop for the columns
    for (int col = 0; col < 3; col++)

        //for loop for rows
        for (int row = 0; row < 3; row++)

            //fill the 9 positions of the array with blank spaces
            board[col][row] = ' ';
}

//functions that displays the array into a board
void displayBoard(void)
{

    //for loop that prints the board lines
    for (int i = 0; i < 3; i++)
    {
        
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);

        if (i != 2)
            printf("\n---|---|---\n");
    }

    printf("\n");
}

//functions that get the input from the player
void getPlayer1(void)
{
    //declares two integers for the coordinates
    int col, row;

    printf("Player 1 please enter a column (1 to 3) and a row (1 to 3): ");

    //get the user input and stores it
    scanf("%d%*c%d", &col, &row);

    //subtracts 1 from the user input to match the one stored into the array
    col--;
    row--;

    //if the array block is not blank
    if (board[col][row] != ' ')
    {
        //error, the block is not empty
        printf("ERROR, try again.\n");

        //retry to get another input
        getPlayer1();
    }

    //otherwise it stores the value X in the block
    else
        board[col][row] = 'X';
}

//functions that get the input from the player 2
void getPlayer2(void)
{
    //declares two integers for the coordinates
    int col, row;

    printf("Player 2 please enter a column (1 to 3) and a row (1 to 3): ");

    //get the user input and stores it
    scanf("%d%*c%d", &col, &row);

    //subtracts 1 from the user input to match the one stored into the array
    col--;
    row--;

    //if the array block is not blank
    if (board[col][row] != ' ')
    {
        //error, the block is not empty
        printf("ERROR, try again.\n");

        //retry to get another input
        getPlayer2();
    }

    //otherwise it stores the value X in the block
    else
        board[col][row] = 'O';
}

//return a char that estabilish if there are the winning condition for the game
char winCondition(void)
{

    //for loops that checks the board columns for 3 pieces in line
    for (int col = 0; col < 3; col++)

        if (board[col][0] == board[col][1] &&

            board[col][0] == board[col][2])
            return board[col][0];

    //for loops that checks the board rows for 3 pieces in line
    for (int row = 0; row < 3; row++)

        if (board[0][row] == board[1][row] &&

            board[0][row] == board[2][row])
            return board[0][row];


    //condition to check the board diagonals for 3 pieces in line
    
    //from the upper left 
    if (board[0][0] == board[1][1] &&

        board[1][1] == board[2][2])

        return board[0][0];

    //from the upper right
    if (board[0][2] == board[1][1] &&

        board[1][1] == board[2][0])

        return board[0][2];

    //otherwise the win string remains blank
    return ' ';
}

//function the enable the computer to print a nought in the first blank block available
void autoMove()
{
    //declares two integers for the coordinates
    int col, row;

    //loop the columns
    for (col = 0; col < 3; col++)
    {
        //loop the rows
        for (row = 0; row < 3; row++)

            //first blank block break the loop
            if (board[col][row] == ' ')
                break;

        //first blank block break loop
        if (board[col][row] == ' ')
            break;
    }

    //if no blank spaces and no win condition
    if (col * row == 9)
    {
        //then the game is draw
        printf("DRAW!\n");

        exit(0);
    }

    //otherwise
    else
        //write in the block
        board[col][row] = 'O';
}

//functions for the more heuristic AI
void getAI(void)
{
    //declares two integers for the coordinates
    int col, row;

    //loop for the columns
    for (col = 0; col < 3; col++)
    {
        //loop for the row
        for (row = 0; row < 3; row++)
        {
            //check for the upper right corner
            if (board[0][0] == ' ' && board[0][0] != 'X')
            {
                //check for the down left corner
                if (board[2][0] == ' ' && board[2][0] != 'X')
                {
                    //check for the upper left corner
                    if (board[0][2] == ' ' && board[0][2] != 'X')
                    {
                        //check for the down right corner
                        if (board[2][2] == ' ' && board[2][2] != 'X')
                        {
                            //if blank write in it
                            board[2][2] = 'O';
                            break;
                        }

                        //otherwise
                        else
                        {
                            //write in it
                            board[0][2] = 'O';
                            break;
                        }
                    }

                    //otherwise
                    else
                    {
                        //write in it
                        board[2][0] = 'O';
                        break;
                    }
                }

                //otherwise
                else
                {
                    //write in it
                    board[0][0] = 'O';
                    break;
                }
                break;
            }

            //if none of the corner is free write in the first available blank space
            else if (board[col][row] == ' ' && board[col][row] != 'X')
            {
                board[col][row] = 'O';
                break;
            }

            //if no blank spaces and no win condition
            else if (col * row == 9)
            {
                //then the game is draw
                printf("draw\n");

                exit(0);
            }

            break;
        }
        break;
    }
}
