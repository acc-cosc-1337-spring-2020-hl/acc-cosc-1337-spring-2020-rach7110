#include "tic_tac_toe.h"

using std::cout;

void TicTacToe::start_game(string first_player)
{
    if (first_player != 'X' || first_player != '0')
    {
        throw Exception("Player must be X or O");
    }

    player = first_player;
}
mark_board(int position)

//1) Value of int must be in the range 1 to 9;
// otherwise, throw an Error exception if value not in this range.  Error Message: Position must be 1 to 9.
//2) Private data player can’t be empty “”, throw an Error exception if player variable is “”.
// Error Message: Must start game first.
//
//3) Call set_next_player private function

void TicTacToe::mark_board(int position)
{
    if (position < 1 || position > 9)
    {
        throw Error("Position must be 1 to 9.")
    }

    if (!player)
    {
        throw Error("Must start game first.")
    }

    set_next_player();
}

string TicTacToe::get_player()
{
    return player;
}

void TicTacToe::set_next_player()
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}

string Error::get_message()
{
    return message;
}