#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_3.h"
#include<iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    REQUIRE_THROWS_AS(game->mark_board(1), GameError);
}

TEST_CASE("Test start game accepts only X or O") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    REQUIRE_THROWS_AS(game->start_game("R"), GameError);
}

TEST_CASE("Test set first player to X") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    game->start_game("X");

	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test set first player to O") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    game->start_game("O");

    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test start game with X game flow") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    game->start_game("X");
	REQUIRE(game->get_player() == "X");

    game->mark_board(4);
    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test start game with O game flow") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    game->start_game("O");
	string player = game->get_player();


    REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test mark positiion only accepts values 1 to 9.") {
    unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
    game->start_game("O");
    game->mark_board(4);
    
    REQUIRE_THROWS_AS(game->mark_board(10), GameError);
}

TEST_CASE("Test game over when board full. No Winner.") {
	unique_ptr<TicTacToe> game = make_unique<TicTacToe3>;
	game->start_game("X");

	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);

	game->mark_board(4);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == false);

	game->mark_board(8);
	REQUIRE(game->game_over() == false);

	game->mark_board(7);
	REQUIRE(game->game_over() == false);

	game->mark_board(9);
    
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by first column", "[X wins first column]")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(1);//X
    board.mark_board(2);//O
    board.mark_board(4);//X
    board.mark_board(5);//O
    board.mark_board(7);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second column", "[X wins second column]")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(2);//X
    board.mark_board(3);//O
    board.mark_board(5);//X
    board.mark_board(7);//O
    board.mark_board(8);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third column", "[X wins third column]")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(3);//X
    board.mark_board(1);//O
    board.mark_board(6);//X
    board.mark_board(2);//O
    board.mark_board(9);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by first row", "[X wins first row]")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(1);//X
    board.mark_board(5);//O
    board.mark_board(2);//X
    board.mark_board(6);//O
    board.mark_board(3);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(4);//X
    board.mark_board(3);//O
    board.mark_board(5);//X
    board.mark_board(2);//O
    board.mark_board(6);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(7);//X
    board.mark_board(1);//O
    board.mark_board(8);//X
    board.mark_board(2);//O
    board.mark_board(9);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win diagonally from top left")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(1);//X
    board.mark_board(2);//O
    board.mark_board(5);//X
    board.mark_board(3);//O
    board.mark_board(9);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win diagonally from top right")
{
    TicTacToe3 board;
    board.start_game("X");
    board.mark_board(7);//X
    board.mark_board(2);//O
    board.mark_board(5);//X
    board.mark_board(1);//O
    board.mark_board(3);//X wins
    
    REQUIRE(board.get_winner() == "X");
    REQUIRE(board.game_over() == true);
}
