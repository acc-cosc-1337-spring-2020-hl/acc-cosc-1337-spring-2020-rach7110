#include "tic_tac_toe.h"

using std::cout;
using std::cin;

int main() 
{
    TicTacToe game;
    string first_player;

	do {
		cout << "Enter player: ";
		cin >> first_player;

		try {
			game.start_game(first_player);
		}
		catch (GameError e) {
			cout << e.get_message();
		} 

		cout << game.get_player();
		//mark_board(int position)

		
	} while (first_player != "exit");


    return 0;
}