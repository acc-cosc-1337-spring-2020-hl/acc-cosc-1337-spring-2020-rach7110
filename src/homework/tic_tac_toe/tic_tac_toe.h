#ifndef TIC_TACTOE_H
#define TIC_TAC_TOE_H

#include<iostream>
#include<string>

using std::string;

class TicTacToe
{
    public:
        void start_game(string first_player);
        void mark_board(int position);
        string get_player();


private:
        void set_next_player();
        string player;
};

class GameError
{
    public:
		GameError(string msg) : message{ msg } {};
        string get_message();
    private:
        string message;
};



#endif