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
        TicTacToe(vector<string> p, string win) : pegs{p}, winner{win}{}
		bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player();
        string get_winner();
        vector<string> get_pegs()const { return pegs; }
        friend istream &operator>>(istream &in, TicTacToe &board);
        friend ostream &operator<<(ostream &out, const TicTacToe& board);

    protected:
        vector<string> pegs;
        virtual bool check_column_win() = 0;
        virtual bool check_row_win() = 0;
        virtual bool check_diagonal_win() = 0;
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
