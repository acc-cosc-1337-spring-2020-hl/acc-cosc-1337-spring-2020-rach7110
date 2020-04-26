#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique;

int main() 
{
    unique_ptr<TicTacToeManager> manager;
    
    vector<unique_ptr<TicTacToe> >games;
    bool playing = true;
    int size;

    do {
       
        string first_player;
        
        cout << "Choose TicTacToe3 or TicTacToe4 (3 or 4): \n";
        cin >> size;
    
        unique_ptr<TicTacToe> game_3 = make_unique<TicTacToe3>;
        unique_ptr<TicTacToe> game_4 = make_unique<TicTacToe4>;

        if (size == 3) {
            games.push_back(move(game_3));
        }
        
        if (size == 4) {
            games.push_back(move(game_4));
        }
        
        cout << "Enter first player (X or O): ";
        cin >> first_player;
        
        // Invalid first player.
        try {
            games.back().get()->start_game(first_player);
        }
        catch (GameError e) {
            cout << e.get_message() << "\n";
        }
        
        unique_ptr<TicTacToe> game = games.back();

        // Play game.
        do {
            cin >> game.get();
            cout << game.get();

        } while (!game.get()->game_over());
        
        // Game is over, so output results and ask if user wants to play again.
        if (game.get()->game_over()) {
            cout << "Game over! \n";
            manager->save_game(std::move(game.get()));
            cout << *manager;
            manager->get_winner_totals();
            
            cout << "Play again? (Enter 1-Yes, 0-No) \n";
            cin >> playing;
        }
    } while (playing);
    
    return 0;
}
