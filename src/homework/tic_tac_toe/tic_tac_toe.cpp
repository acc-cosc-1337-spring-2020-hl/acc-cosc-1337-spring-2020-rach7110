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
    if (position < 1 || position > 9)
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
		set_next_player();
	}

}

string TicTacToe::get_player()
{
    return player;
}

void TicTacToe::display_board() const
{
	cout << "\n";

	for (int i=0; i<=8; i += 3)
	{
		cout << pegs[i] << "|" << pegs[i + 1] << "|" <<  pegs[i + 2] << "\n";
	}

	cout << "\n";
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
    if (player == "X") {
        winner = "O";
    } else {
        winner = "X";
    };
}

// A diagonal wins with marked values 1,5,9 or 7,5,3 with all Os or Xs
bool TicTacToe::check_diagonal_win() { 
    if ((pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")  || (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O") ) {
         set_winner();
		 return true;
     }
     
     if ((pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")  || (pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O") ) {
         set_winner();
		 return true;
     }

	 return false;
}

// A row wins with marked values 1,2,3 or 4,5,6 or 7,8,9 with all Os or Xs
bool TicTacToe::check_row_win() { 
    if ((pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")  || (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O") ) {
        set_winner();
		return true;
    }
    
    if ((pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")  || (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O") ) {
        set_winner();
		return true;
    }
    
    if ((pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")  || (pegs[2] == "O" && pegs[6] == "O" && pegs[7] == "O") ) {
        set_winner();
		return true;
    }

	return false;
}

// A column wins with marked values 1,4,7 or 2,5,8, or 3,6,9 with all Os or Xs
//(Remember a vector index starts at 0)
bool TicTacToe::check_column_win() { 
    if ((pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")  || (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O") ) {
        set_winner();
		return true;
    }
    
    if ((pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")  || (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O") ) {
        set_winner();
		return true;
    }
    
    if ((pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")  || (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O") ) {
        set_winner();
		return true;
    }

	return false;
}

string GameError::get_message()
{
    return message;
}
