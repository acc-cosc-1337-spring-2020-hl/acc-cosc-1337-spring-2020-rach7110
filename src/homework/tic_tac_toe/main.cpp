#include "tic_tac_toe.h"

using std::cout;
using std::cin;

int main() 
{
    TicTacToe game;
    string first_player;

    do {
        try {
            cout << "Enter first player (X or O): ";

            cin >> first_player;
            
            game.start_game(first_player);
        }
        catch (GameError e) {
            cout << e.get_message() << "\n";
        }
    } while (game.get_player() == "");

    do {
        cin >> game;

        cout << game;

//	} while (position != 100 && !game.game_over());
    } while (!game.game_over());  // TODO: implement way for user to exit game.s
    
    return 0;
}
