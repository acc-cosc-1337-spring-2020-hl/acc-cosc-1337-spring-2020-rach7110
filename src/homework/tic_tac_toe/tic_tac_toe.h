#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;
using std::cout;
using std::istream;
using std::ostream;

class TicTacToe
{
    public:
        TicTacToe(int s = 3) : pegs(s*s, " "){};
		bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player();
        string get_winner();
        friend istream &operator>>(istream &in, TicTacToe &board);
        friend ostream &operator<<(ostream &out, TicTacToe board);

    protected:
        vector<string> pegs;
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();
        void set_winner();
        bool check_board_full();
    
    private:
        void set_next_player();
		void clear_board();
        string player = "";
        string winner = "C";
		
};

class GameError
{
    public:
		GameError(string msg) : message(msg) {};
        string get_message();
    private:
        string message;
};



#endif
