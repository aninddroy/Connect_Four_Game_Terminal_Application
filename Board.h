#pragma once
/*******************************************************************/
/* Header file - Board.h */

/* Connect Four Game */

/* Description */

/* Connect Four(or Vier op een rij in Dutch) is a two - player connection board game, in         */
/* which the players choose a colorand then take turns dropping colored discs into a             */
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

	enum class player_and_result
	{
		yellow = 1,
		red = 2,
		draw = 3,
		game_not_complete = 4
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
		void print_board();
		bool is_game_complete();
		player_and_result get_result();
		//the board can be set by the unit tests or any user application
		void set_board(const std::vector<std::vector<char>>& source_board);
		//if the game is to be run multiple times by the unit tests, it is better to
		//set the game completion status to false
		void set_game_complete_status(bool game_complete_status);
		//takes the user/human input, that is the column number which the human
		//wants to fill in
		void take_human_input();
		//this function generates the position/column number that the machine wants to fill in
		void generate_machine_input();
		//checks if the position in the board is empty, that is 'W' to fill in by the player, human or machine
		bool check_if_empty_position(int column_number);
		//marks position on the board either by the human player or machine player
		void mark_position_on_board(char ch, int column_number);
		void select_position_on_board();
		//checks if there is a winner
		void check_for_connected_disks();
		void run_game();

	private:

		std::vector<std::vector<char>> board{
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
			{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' }
		};

		player_and_result result;
		player_and_result human_player;
		player_and_result machine_player;
		player_and_result turn;
		int human_entered_column_number;
		int machine_entered_column_number;
		char quit_game_or_continue;
		bool game_complete;
	};


}// end of namespace connect_four
