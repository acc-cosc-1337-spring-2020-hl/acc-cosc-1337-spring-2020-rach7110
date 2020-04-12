#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    void save_game(TicTacToe game);
    friend ostream &operator<<(ostream &out, const TicTacToeManager &manager);
    void get_winner_totals();
    
private:
    vector<TicTacToe> games;
    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;
    void update_winner_count(string winner);
};

#endif
