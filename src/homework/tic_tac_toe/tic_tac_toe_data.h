#ifndef TIC_TAC_TOE_DATA_H
#define TIC_TAC_TOE_DATA_H

#include "tic_tac_toe.h"
#include<memory>

using std::unique_ptr;

class TicTacToeData
{
    public:
        void save_game(const vector<unique_ptr<TicTacToe> > &games);
        vector<unique_ptr<TicTacToe> > get_games();
    private:
//        const std::string file_name{"games.dat"}
};


#endif
