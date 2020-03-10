#ifndef TIC_TACTOE_H
#define TIC_TAC_TOE_H

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;
using std::cout;

class TicTacToe
{
    public:
		bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player();
		void display_board()const;

private:
        void set_next_player();
		bool check_board_full();
		void clear_board();
        string player;
		vector<string> pegs{9, " "};
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