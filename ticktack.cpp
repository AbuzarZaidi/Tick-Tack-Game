#include<iostream>
using namespace std;
char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, { '7', '8', '9' } };
char turn = 'X';
int row, colum;
bool draw = false;
void display_board()
{
	system("cls");
	cout << "\t\t\tTICK TACK GAME \n \n";
	cout << "Player 1:  X" << endl;
	cout << "Player 2:  O\n\n" << endl;
	cout << "\t\t     |     |       " << endl;
	cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "    " << endl;
	cout << "\t\t_____|_____|_____  " << endl;
	cout << "\t\t     |     |       " << endl;
	cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "    " << endl;
	cout << "\t\t_____|_____|_____  " << endl;
	cout << "\t\t     |     |       " << endl;
	cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "    " << endl;
	cout << "\t\t     |     |       \n\n" << endl;


}

void player_turn()
{
	if (turn == 'X')
	{
		cout << "\n\n player 1 [X] turn: " << endl;
	}
	if (turn == 'O')
	{
		cout << "\n\n player 1 [O] turn: " << endl;
	}
	int choice;

	cin >> choice;
	switch (choice)
	{
	case 1:
		row = 0; colum = 0;
		break;
	case 2:
		row = 0; colum = 1;
		break;
	case 3:
		row = 0; colum = 2;
		break;
	case 4:
		row = 1; colum = 0;
		break;
	case 5:
		row = 1; colum = 1;
		break;
	case 6:
		row = 1; colum = 2;
		break;
	case 7:
		row = 2; colum = 0;
		break;
	case 8:
		row = 2; colum = 1;
		break;
	case 9:
		row = 2; colum = 2;
		break;
	default:
		cout << "Invalid Entry." << endl;
	}
	if (turn == 'X' && board[row][colum] != 'X' && board[row][colum] != 'O')
	{
		board[row][colum] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][colum] != 'X' && board[row][colum] != 'O')
	{
		board[row][colum] = 'O';
		turn = 'X';
	}
	else {
		cout << "wrong entry \n try again" << endl;
		player_turn();
	}
	display_board();
}

bool game_over()
{

	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return false;
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
	{
		return false;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				return true;
			}
		}
	}
	draw = true;
	{
		return false;
	}
}


int main()
{

	while (game_over())
	{

		display_board();
		player_turn();
		game_over();
	}
	if (turn == 'X' && draw == false)
	{
		cout << "Player 2 [O]: WIN! \"Congratulation\"" << endl;
	}
	else if (turn == 'O' && draw == false)
	{
		cout << "Player 1 [X]: WIN! \"Congratulation\"" << endl;
	}
	else
	{
		cout << "GAME DRAW. " << endl;
	}

	system("pause");
	return 0;
}

