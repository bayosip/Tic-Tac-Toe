#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define ROWS 4
#define COLS 4
#define EMPTY '.'
#define NOUGHT 'O'
#define CROSS 'X'

//char* chooseSymbol();
//void makeMove (char board[ROWS][COLS], const int row, 
	//const int col, const char side);

void initializeBoard(char board[ROWS][COLS]);
void printBoard (char board[ROWS][COLS]);
void runGame();
char chooseSymbol();
void makeMove (char board[ROWS][COLS], int play, const char side);
int isEmpty (char board[ROWS][COLS]);
int checkForWin (char board[ROWS][COLS], char side);
int getHumanMove(char board[ROWS][COLS]);
int getCpuMove(char board[ROWS][COLS]);

int main(){
	printf ("******************************************************************\n");
	printf ("*This program is a  Tic Tac Toe program, of a 4 x 4 grid style%3c*\n");
	printf ("*Player is assigned NOUGHT, and to play on turn enter 0-15, %5c*\n");
	printf("which represents on grid as follows:%29c*\n");
	printf ("******************************************************************\n\n");
	
	printf("******************\n"
		   "*  0|  1|  2| 3  *\n"
		   "*----------------*\n"
		   "*  4|  5|  6| 7  *\n"
		   "*----------------*\n"
		   "*  8|  9| 10| 11 *\n"
		   "*----------------*\n"
		   "* 12| 13| 14| 15 *\n");
	printf("******************\n\n");
		   
	
	runGame();
	//do{}while();
	system ("pause");
	return 0;

}

void initializeBoard(char board[ROWS][COLS]){

	int row =0;
	int col = 0;

	for (row = 0; row <ROWS; row++){
	
		for (col = 0; col< COLS; col++){
				board[row][col] = EMPTY;
		}
	} 
}

void runGame(){

	int gameOver = 0;
	int lastMoveMade= 0;
	char board[ROWS][COLS];
	char player, side = CROSS;
	/* Initializing the board*/
	initializeBoard(board);
	//print empty board
	printBoard (board);

	//player = chooseSymbol();
	//player = chooseSymbol()[0];
	//cpu = chooseSymbol()[1];
	//side = player;

	while (!gameOver){//Human turn to play
		if (side==CROSS){
			lastMoveMade = getHumanMove(board);
			makeMove(board, lastMoveMade,side);
			printBoard (board);
			gameOver = checkForWin (board, side);
			printf ("\nPlayer made move on Sq: %d\n", lastMoveMade);
			side = NOUGHT;
		}
		else{//CPU's turn to play
			lastMoveMade = getCpuMove(board);
			makeMove(board,lastMoveMade,side);
			printBoard (board);
			gameOver = checkForWin (board, side);
			printf ("\nCPU made move on Sq: %d\n", lastMoveMade);
			side = CROSS;
		}

		//if there are no more moves
		if (!isEmpty (board)){
			printf("\nGame over!\n");
			gameOver = 1;
			printf("\n******Its a draw...!!!******\n");
		}
	}
}

void printBoard (char board[][COLS]){
	int row = 0;
	int col = 0;
	printf("\n============== Board ================ \n\n");
	//printf("   |   |   |   |\n");
	for (row = 0; row<ROWS; row++){
		if (row!=0){
			printf(" ----------------");
			printf("\n");
		}
		for (col = 0; col<COLS; col++){
		printf("%3c|", board[row][col]);
	}
	
		printf("\n");
		
	}
	printf("\n");
}

/*This function allows the human player to select a side*/
/*char chooseSymbol(){

char temp;
int choice, go =0;
while (go == 0){

printf("Player please select a symbol to play with:\n" 
	"1) Nought \'O\' or,\n"
	"2) Cross \'X\'?\n"
	": ");
scanf("%d", &choice);



	
	if (choice == 1){
	temp = NOUGHT;
	go = 1;
	}
	else if (choice == 2){
	temp = CROSS;
	go = 1;
	}
	else {
		printf ("Invalid choice\n");
		continue;
	}
}

/*switch (choice){

case 1:
	//temp = NOUGHT;
	temp[0] = NOUGHT;
	temp[1] = CROSS;
	break;

case 2:
	//temp = CROSS;
	temp[0] = CROSS;
	temp[1] = NOUGHT;
	break;

default:
	printf ("Invalid choice\n");
	break;
}
return temp;
}*/

void makeMove (char board[ROWS][COLS], int play, const char side){
	int row, col;
	if (play <4){
		row=0;
		col= play;
	}
	else {

		row = play/4;
		col = play%4;
	}
		board [row][col] = side;
}

int isEmpty (char board[ROWS][COLS]){
	int row =0;
	int col = 0;

	for (row = 0; row <ROWS; row++){
	
		for (col = 0; col< COLS; col++){
			if (board[row][col] == EMPTY)
				return 1;				
		}
	} 
	return 0;
}
int gameWon (char board[ROWS][COLS], int play, const char side){
	int row, col;
	if (play <4){
		row=0;
		col= play--;
	}
	else {

		row = play/4;
		col = play%4;
		}
	for (row = 0; row <ROWS; row++){
	
		for (col = 0; col< COLS; col++){
			if (board[row][col] == EMPTY){
				return 1;				
			}
		}
	}
		return 0;
}

int checkForWin (char board[ROWS][COLS], char side){
	int row =0;
	int col = 0;

	for (row = 0; row <ROWS; row++){
		for (col = 0; col< COLS; col++){
			if ((board[row][col] == side && board[row][col+1] == side &&
				board[row][col+2] == side && board[row][col+3] == side) || 
				(board[row][col] == side && board[row+1][col] == side && 
				board[row+2][col] == side && board[row+3][col] == side) ||
				(board[row][col] == side && board[row+1][col+1] == side &&
				board[row+2][col+2] == side && board[row+3][col+3] == side)||
				(board[row][col+3] == side && board[row+1][col+2] == side &&
				board[row+2][col+1] == side && board[row+3][col+0] == side)){
					if (side == CROSS){
						
						printf ("\nCongrats!!! Human player has won the game!\n", side);
					}
					else {
						printf ("\nYou Lose!!!\n");
					}
					

				return 1;
			}
		}
	} 
	return 0;
}

/*This function gets the humans move which are from 0-15
  the user input is checked for errors*/
int getHumanMove(char board[ROWS][COLS]){

	char userInput [4];

	int moveOk = 0;
	int move = -1;
	int row, col;

	while (moveOk == 0){
		printf("\nPlease enter a move from 0 to 15: ");
		fgets(userInput, 3, stdin);
		fflush(stdin);

		if (strlen(userInput) !=2){//check 
				printf("invalid input!\n");
				continue;
		}
		
		if (sscanf(userInput, "%d", &move) !=1 ){
			move =-1;
			printf("Invalid input!\n");
			continue;
		}

		if (move >15){
			move =-1;
			printf("Invalid input!\n");
			continue;
		}
		
		if (move <4){
			
			row= 0;
			col = move;
			if (board [row][col] != EMPTY){
		
			move = -1;
			printf ("\nThis square is not empty!");
			continue;
			}
		}
		else {
		row = move/4;
		col = move%4;
		if (board [row][col] != EMPTY){
		
			move = -1;
			printf ("This square is not empty!\n");
			continue;
			}
		}		
		moveOk = 1;
	}
	printf("Making move at position: %d\n", move);
	return move;
}

int getCpuMove(char board[ROWS][COLS]){
	int availableMoves[16];
	int spaceFree = 0;
	int row = 0;
	int col = 0;
	int freeSq = 0;
	int moveOk = 0;
	srand(time(NULL));
	unsigned int move = 0;

	while (moveOk == 0){
	for (row = 0; row <ROWS; row++){
		for (col = 0; col< COLS; col++){
			if (board[row][col] == EMPTY){
				freeSq = (row * 4) + col;
				availableMoves[freeSq++] = freeSq;	
			}
			else{
				move = -1;
				continue;
			}
		}
	}	
	move = (rand()&0xF);
	if ((move <0)||(move >15)){
		continue;
	}
		moveOk = 1;
	}
	
	return availableMoves[move];
}

