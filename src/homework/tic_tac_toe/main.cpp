#include "tic_tac_toe.h"

using std::cout;
using std::cin;

int main() 
{
    TicTacToe game;
    string first_player;
    int position;

    cout << "Enter first player (X or O): ";
    cin >> first_player;

    try {
        game.start_game(first_player);
    }
    catch (GameError e) {
        cout << e.get_message();
    }

    do {
        cout << "\nPlayer " << game.get_player() << ", enter a position (1-9) or 100 to quit: \n";

        cin >> position;

        try {
            game.mark_board(position);
			game.display_board();
        } catch (GameError e) {
            cout << e.get_message();
        }

	} while (position != 100 && !game.game_over());


    return 0;
}