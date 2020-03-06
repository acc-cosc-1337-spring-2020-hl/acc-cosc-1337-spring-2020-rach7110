#include "tic_tac_toe.h"

using std::cout;
using std::cin;

int main() 
{
    TicTacToe game;
    string first_player;

    cout << "Enter first player: ";
    cin >> first_player;

    try {
        game.start_game(first_player);
    }
    catch (Error e) {
        cout << e.get_message();
    }

	//mark_board(int position)


    return 0;
}