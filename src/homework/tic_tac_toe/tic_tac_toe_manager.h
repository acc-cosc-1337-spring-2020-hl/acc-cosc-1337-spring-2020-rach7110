#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include<memory>
#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"

using std::unique_ptr;

class TicTacToeManager
{
public:
    TicTacToeManager() = default;
    TicTacToeManager(TicTacToeData &d);
    ~TicTacToeManager();
    void save_game(unique_ptr<TicTacToe> &game);
    friend ostream &operator<<(ostream &out, const TicTacToeManager &manager);
    void get_winner_totals();
    
private:
	vector<unique_ptr<TicTacToe> > games;
    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;
    void update_winner_count(string winner);
    TicTacToeData data;
};

#endif
