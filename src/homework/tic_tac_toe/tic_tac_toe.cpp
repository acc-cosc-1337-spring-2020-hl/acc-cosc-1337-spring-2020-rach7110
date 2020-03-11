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

	for (int i=0; i<=9; i += 3)
	{
		cout << pegs[i] << "|" << pegs[i + 1] << "|" <<  pegs[i + 2] << "\n";
	}

	cout << "\n";
}

bool TicTacToe::game_over()
{
	return check_board_full();;
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

	return false;
}

void TicTacToe::clear_board()
{
	for (auto &peg : pegs)
	{
		peg = " ";
	}
}



string GameError::get_message()
{
    return message;
}