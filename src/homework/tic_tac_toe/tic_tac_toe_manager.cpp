#include "tic_tac_toe_manager.h"


void TicTacToeManager::save_game(TicTacToe game)
{
    games.push_back(game);
    
    update_winner_count(game.get_winner());
}

// TODO: is this method necessary?
void TicTacToeManager::get_winner_totals(int &o, int &x, int &t)
{
    
}

void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X") {
        ++x_wins;
    } else if (winner == "O") {
        ++o_wins;
    } else if (winner == "C") {
        ++ties;
    }
        
}

ostream &operator<<(ostream &out, const TicTacToeManager &manager)
{
    for(auto game : manager.games) {
        cout << game;
        cout << "Winner: " << game.get_winner();
        
    }
}
