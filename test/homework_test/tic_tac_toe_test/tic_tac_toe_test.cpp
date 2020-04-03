#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include<iostream>

using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test can’t call mark board before start game") {
    TicTacToe game;
    REQUIRE_THROWS_AS(game.mark_board(1), GameError);
}

TEST_CASE("Test start game accepts only X or O") {
    TicTacToe game;
    REQUIRE_THROWS_AS(game.start_game("R"), GameError);
}

TEST_CASE("Test set first player to X") {
    TicTacToe game;
    game.start_game("X");

	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test set first player to O") {
    TicTacToe game;
    game.start_game("O");

    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with X game flow") {
    TicTacToe game;
    game.start_game("X");
	REQUIRE(game.get_player() == "X");

    game.mark_board(4);
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test start game with O game flow") {
    TicTacToe game;
    game.start_game("O");
	string player = game.get_player();


    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over when board full") {
	TicTacToe game;
	game.start_game("X");

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == false);

	game.mark_board(7);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
    
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first column", "[X wins first column]")
{
    TicTacToe board;
    board.start_game("X");
    board.mark_board(1);//X
    board.mark_board(2);//O
    board.mark_board(4);//X
    board.mark_board(5);//O
    board.mark_board(7);//X wins
    
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second column", "[X wins second column]")
{
    TicTacToe board;
    board.start_game("X");
    board.mark_board(2);//X
    board.mark_board(3);//O
    board.mark_board(5);//X
    board.mark_board(7);//O
    board.mark_board(8);//X wins
    
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third column", "[X wins third column]")
{
    TicTacToe board;
    board.start_game("X");
    board.mark_board(3);//X
    board.mark_board(1);//O
    board.mark_board(6);//X
    board.mark_board(2);//O
    board.mark_board(9);//X wins
    
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by first row", "[X wins first row]")
{
    TicTacToe board;
    board.start_game("X");
    board.mark_board(1);//X
    board.mark_board(5);//O
    board.mark_board(2);//X
    board.mark_board(6);//O
    board.mark_board(3);//X wins
    
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by second row", "[X wins second row]")
{
    TicTacToe board;
    board.start_game("X");
    board.mark_board(4);//X
    board.mark_board(3);//O
    board.mark_board(5);//X
    board.mark_board(2);//O
    board.mark_board(6);//X wins
    
    REQUIRE(board.game_over() == true);
}

TEST_CASE("Test win by third row", "[X wins third row]")
{
    TicTacToe board;
    board.start_game("X");
    board.mark_board(7);//X
    board.mark_board(1);//O
    board.mark_board(8);//X
    board.mark_board(2);//O
    board.mark_board(9);//X wins
    
    REQUIRE(board.game_over() == true);
}
