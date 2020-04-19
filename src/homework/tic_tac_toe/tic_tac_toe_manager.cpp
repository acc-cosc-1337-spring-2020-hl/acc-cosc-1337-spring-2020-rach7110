#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe game)
{
    update_winner_count(game.get_winner());
}

void TicTacToeManager::get_winner_totals()
{
    cout << "Totals: \n";
    cout << "X wins: " << x_wins << "\n";
    cout << "O wins: " << o_wins << "\n";
    cout << "Ties: " << ties << "\n";
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

// Display winner and board.
ostream &operator<<(ostream &out, const TicTacToeManager &manager)
{
    for(auto &game : manager.games) {
        cout << game;
//        cout << "Winner: " << game.get_winner() << "\n\n";
    }
        
    return out;
}
