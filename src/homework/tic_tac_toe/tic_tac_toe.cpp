#include "tic_tac_toe.h"

void TicTacToe::start_game(string first_player)
{
    if (first_player != "X" && first_player != "O")
    {
        throw GameError("Player must be X or O");
    }

	clear_board();
    player = first_player;
}

void TicTacToe::mark_board(int position)
{
    if (position < 1 || position > 9)  // TODO: account for larger boards.
    {
		throw GameError("Position must be 1 to 9.");
    }

    if (player == "")
    {
		throw GameError("Must start game first.");
    }
	else 
	{
		pegs[position - 1] = player;
        
        if (!game_over()) {
            set_next_player();
        }
	}

}

string TicTacToe::get_player()
{
    return player;
}

bool TicTacToe::game_over()
{
    check_row_win();
    check_column_win();
    check_diagonal_win();
    
	return check_board_full() || winner != "C";
}

void TicTacToe::set_next_player()
{
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}
    
bool TicTacToe::check_board_full()
{	
	for (auto peg : pegs) {
		if (peg == " ")
		{
			return false;
		}
	}

	return true;
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}

string TicTacToe::get_winner() { 
    return winner;
}

// If player is X set winner to O otherwise set winner to X
void TicTacToe::set_winner() {
    winner = player;
}

// A diagonal wins with marked values 1,5,9 or 7,5,3 with all Os or Xs
bool TicTacToe::check_diagonal_win() {
//    cout << "Check_win called from base class";
	 return false;
}

// A row wins with marked values 1,2,3 or 4,5,6 or 7,8,9 with all Os or Xs
bool TicTacToe::check_row_win() {
	return false;
}

// A column wins with marked values 1,4,7 or 2,5,8, or 3,6,9 with all Os or Xs
//(Remember a vector index starts at 0)
bool TicTacToe::check_column_win() {
	return false;
}


// Overloaded oeprator - gets user selected positiion and marks board.
istream &operator>>(istream &in, TicTacToe &board)
{
    int position;
    
    cout << "\nPlayer " << board.get_player();
    
    if (board.pegs.size() == 9) {
        cout << ", enter a position (1-9)";
    }

    if (board.pegs.size() == 16) {
        cout << ", enter a position (1-16)";
    }
    
    cout << " or 100 to quit: \n";

    in >> position;
    board.mark_board(position);
    
    return in;
}
    
ostream &operator<<(ostream &out, TicTacToe board)
{
    cout << "\n";
    
    // Show board for TicTacToe 3
    if (board.pegs.size() == 9) {
        for (int i=0; i<=board.pegs.size() - 1; i += 3) {
            cout << board.pegs[i] << "|" << board.pegs[i + 1] << "|" <<  board.pegs[i + 2] << "\n";
        }
    }
    
    // Show board for TicTacToe 4
    if (board.pegs.size() == 16) {
        for (int i=0; i<=board.pegs.size() - 1; i += 4) {
            cout << board.pegs[i] << "|" << board.pegs[i + 1] << "|" <<  board.pegs[i + 2] << "|" <<  board.pegs[i + 3] << "\n";
        }
    }

    cout << "\n";
    
    return out;
}

string GameError::get_message()
{
    return message;
}
