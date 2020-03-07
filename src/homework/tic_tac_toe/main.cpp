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
        cout << "\nPlayer " << game.get_player() << ", enter a position (1-9) or 'exit' to quit: \n";

        cin >> position;

        try {
            game.mark_board(position);
        } catch (GameError e) {
            cout << e.get_message();
        }

	} while (position != "exit");


    return 0;
}