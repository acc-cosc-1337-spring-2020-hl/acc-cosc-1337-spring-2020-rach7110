#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"

class TicTacToeManager
{
public:
    void save_game(TicTacToe game);
    friend ostream &operator<<(ostream &out, TicTacToeManager manager);
    void get_winner_totals(int &o, int &x, int &t);  // TODO: is this necessary?
    
private:
    vector<TicTacToe> games;
    int o_win = 0;
    int x_wins = 0;
    int tie = 0;
    void update_winner_count(string winner);
};


#endif
