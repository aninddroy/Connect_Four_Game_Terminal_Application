#pragma once
/*******************************************************************/
/* Header file - Board.h */

/* Connect Four Game */

/* Description */

/* Connect Four(or Vier op een rij in Dutch) is a two - player connection board game, in         */
/* which the players choose a color and then take turns dropping colored discs into a             */
/* seven-column, six-row, vertically suspended grid.The pieces fall straight down, occupying     */
/* the lowest available space within the column.The objective of the game is to be the first to  */
/* form a horizontal, vertical, or diagonal line of four of one's own discs. If the board fills  */
/* up before either player achieves four in a row, then the game is a draw.
/*  Reference to the Game - in the following links                                               */
/* https://www.helpfulgames.com/subjects/brain-training/connect-four.html						 */
/* https://www.cbc.ca/kids/games/all/connect-4													 */

/* Author - Anind Duttaroy */
/*******************************************************************/

#include <iostream>
#include <vector>


namespace connect_four
{
	//Number of columns of the game
	const int board_columns = 7;
	const int board_rows = 6;

	const int board_column_num_min = 1;
	const int board_column_num_max = 7;

	const char white = 'W';
	const char yellow = 'Y';
	const char red = 'R';
	const char yellow_small = 'y';
	const char red_small = 'r';

	enum class player
	{
		yellow = 1,
		red = 2,
		none = 3
	};

	enum class result
	{
		won = 4,
		draw = 5,
		game_not_complete = 6
	};


	class Board
	{
	public:
		Board();

		//Disable the move constructor
		Board(Board&& move_object) = delete;

		//Disable the copy constructor
		Board(const Board& copy) = delete;

		//Disable the assignment operator
		Board& operator=(const Board& copy) = delete;

		//Disable the move assignment operator
		Board& operator=(Board&& move_object) = delete;

		//prints the board
		void PrintBoard() const;

		void RunGame();

		bool IsGameComplete() const;
		bool IsGameQuitted() const;

		result GetResult() const;
		player GetWinner() const;

	private:

		//takes the user/human input, that is the column number which the human
		//wants to fill in
		int TakeHumanInput();
		
		//this function generates the position/column number that the machine wants to fill in
		int GenerateMachineInput();

		//mark the position on board for human or machine input, print board, and check connected position
		bool SetPositionAndCheck(player turn, int column_number);
		
		//checks if the position in the board is empty, that is 'W' to fill in by the player, human or machine
		bool CheckIfEmptyPosition(int column_number) const;
		
		//marks position on the board either by the human player or machine player
		bool MarkPositionOnBoard(player turn, int column_number);
	
		//checks if there is a winner
		void CheckForConnectedDisks();

		//do the actual checcking for connected disks
		bool CheckConnectedDisksAndMarkWinner(const std::pair<int, int>& first_position, 
			const std::pair<int, int>& second_position, 
			const std::pair<int, int>& third_position, 
			const std::pair<int, int>& fourth_position, 
			char color);
		

		//the board for marking positions
		std::vector<std::vector<char>> board{
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' }
		};

		player human_player;
		player machine_player;
		player turn;
		player winner;
		result result;

		bool game_complete;
		bool game_quitted;
	};


}// end of namespace connect_four
