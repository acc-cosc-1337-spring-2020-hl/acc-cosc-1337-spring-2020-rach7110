#include "tic_tac_toe_manager.h"

TicTacToeManager::TicTacToeManager(TicTacToeData &d)
{
    games = d.get_games();
    
    // Get winner counts.
    for (auto& game : games)
    {
        string winner = game->get_winner();
        update_winner_count(winner);
    }
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe> &game)
{
	update_winner_count(game->get_winner());
    games.push_back(std::move(game));
    
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

TicTacToeManager::~TicTacToeManager()
{
    data.save_game(games);
}

// Display winner and board.
ostream &operator<<(ostream &out, const TicTacToeManager &manager)
{
    for(auto &game : manager.games) {
        cout << *game;
        cout << "Winner: " << game->get_winner() << "\n\n";
    }
        
    return out;
}
