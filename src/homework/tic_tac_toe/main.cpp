#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;

int main() 
{
    TicTacToeManager manager;
    TicTacToe3 game_3;
    TicTacToe4 game_4;
    vector<reference_wrapper<TicTacToe> >games;
    bool playing = true;
    int size;

    do {
       
        string first_player;
        
        cout << "Choose TicTacToe3 or TicTacToe4 (3 or 4): \n";
        cin >> size;
        
        if (size == 3) {
            games.push_back(game_3);
            manager.games.push_back(games.front());
        }
        
        if (size == 4) {
            games.push_back(game_4);
            manager.games.push_back(games.back());
        }
        
        cout << "Enter first player (X or O): ";
        cin >> first_player;
        
        // Invalid first player.
        try {
            manager.games.back().get().start_game(first_player);
        }
        catch (GameError e) {
            cout << e.get_message() << "\n";
        }
        
        TicTacToe game = manager.games.back();

        // Play game.
        do {
            cin >> game;
            cout << game;

        } while (!game.game_over());
        
        // Game is over, so output results and ask if user wants to play again.
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
