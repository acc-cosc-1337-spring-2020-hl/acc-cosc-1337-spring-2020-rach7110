#include "tic_tac_toe.h"

void TicTacToe::start_game(string first_player)
{
    if (first_player != "X" || first_player != "O")
    {
        throw GameError("Player must be X or O");
    }

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

    set_next_player();
}

string TicTacToe::get_player()
{
    return player;
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

string GameError::get_message()
{
    return message;
}