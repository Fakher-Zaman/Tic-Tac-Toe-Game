/*---------------------------------------------------*/
/*******************Tick Cross Game.******************/
//This program is demonstrates about designing of TiC 
//TaC ToE Game which we have delared two players data 
//Type and display on Screen.
#include <iostream>
#include <cctype>
#include <conio.h>
using namespace std;

//Global Variables.
char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, column;
bool draw = false;

void display_arr()
{
	system ("cls");
	cout << "\n|******************-[T I C K   Cross   G A M E]-****************|\n\n";
	cout << "\tPlayer 1 --> [X]\n";
	cout << "\tPlayer 2 --> [O]\n\n";
	
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << arr[0][0] << "  |  "  << arr[0][1] <<  "  |  " << arr[0][2] << " \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << arr[1][0] << "  |  "  << arr[1][1] <<  "  |  " << arr[1][2] << " \n";
	cout << "\t\t_____|_____|_____\n";
	cout << "\t\t     |     |     \n";
	cout << "\t\t  " << arr[2][0] << "  |  "  << arr[2][1] <<  "  |  " << arr[2][2] << " \n";
	cout << "\t\t     |     |     \n\n";
}

void player_turn()
{
	int choice;
	
	if (turn == 'X')
	{
		cout << "\n\tPlayer 1 [X] Turn : ";
	}
	
	if (turn == 'O')
	{
		cout << "\n\tPlayer 2 [0] Turn : ";
	}
	
	cin >> choice;
	
	switch (choice)
	{
		case 1 : { row = 0; column = 0; break; }
		case 2 : { row = 0; column = 1; break; }
		case 3 : { row = 0; column = 2; break; }
		case 4 : { row = 1; column = 0; break; }
		case 5 : { row = 1; column = 1; break; }
		case 6 : { row = 1; column = 2; break; }
		case 7 : { row = 2; column = 0; break; }
		case 8 : { row = 2; column = 1; break; }
		case 9 : { row = 2; column = 2; break; }

		default :
		{
			cout << "Invalid choice.\n";
			break;
		}
	}
	
	if (turn == 'X' && arr [row][column] != 'X' && arr [row][column] != 'O')
	{
		arr[row][column] = 'X';
		turn = 'O';
	}
		
	else if (turn == 'O' && arr [row][column] != 'X' && arr [row][column] != 'O')
	{
		arr[row][column] = 'O';
		turn = 'X';
	}
	
	else
	{
		cout << "\nBOX already filled!, Please try again.\n";
		player_turn();
	}
	
	display_arr();        //board update.
}

bool game_over()
{
	//Check Win.
	for (int i = 0; i < 3; i++)
	{
		if (arr [i][0] == arr [i][1] && arr [i][0] == arr [i][2] 
			|| arr [0][i] == arr [1][i] && arr [0][i] == arr [2][i])
		return false;	
		
		if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] 
			|| arr[0][2] == arr[1][1] && arr[0][0] == arr [2][0])
		return false;
	}	
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr [i][j] != 'X' && arr [i][j] != 'O')
			return true;
		}
	}
	
	//Draw The Game.
	draw = true;
	return false;
}

main()
{
	
	while (game_over())
	{	
		display_arr();
		
		player_turn();
			
		game_over();
	}
	
	if (turn == 'X' && draw == false)
	{
		cout << "\aCongratulations, Player 2 [O] Wins!\n";
	}
	
	else if (turn == 'O' && draw == false)
	{
		cout << "\aCongratulations, Player 1 [X] Wins!\n";
	}
	
	else
	{
		cout << "GAME DRAW!! \n";
	}

}

