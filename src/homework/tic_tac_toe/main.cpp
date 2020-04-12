#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;

int main() 
{
    TicTacToeManager manager;
    bool playing = true;

    do {
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

        } while (!game.game_over());
        
        if (game.game_over()) {
            cout << "Game over! \n";
            manager.save_game(game);
            cout << manager;
            manager.get_winner_totals();
            cout << "Play again? (Enter 1-Yes, 0-No) \n";
            cin >> playing;
        }
    } while (playing);
    
    return 0;
}
