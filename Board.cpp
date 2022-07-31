/*******************************************************************/
/* Implementation file - Board.cpp */

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

#include <cstdlib>
#include "Board.h"

namespace connect_four
{
	Board::Board()
		: result(player_and_result::game_not_complete),
		  human_player(player_and_result::yellow),
		  machine_player(player_and_result::red),
		  turn(player_and_result::yellow),
		  human_entered_column_number(0),
		  machine_entered_column_number(0),
		  quit_game_or_continue('c'), 
		  game_complete(false)
	{
	}

	bool Board::is_game_complete()
	{
		return game_complete;
	}

	player_and_result Board::get_result()
	{
		return result;
	}

	void Board::set_board(const std::vector<std::vector<char>>& source_board)
	{
		for (size_t i = 0; i < board_rows; ++i)
		{
			for (size_t j = 0; j < board_columns; ++j)
			{
				board[i][j] = source_board[i][j];
			}
		}
	}

	void Board::set_game_complete_status(bool game_complete_status)
	{
		game_complete = game_complete_status;
	}

	void Board::take_human_input()
	{
		std::cout << std::endl << "Do you want to quit the game? Press c to continue or any other key to quit." << std::endl;
		std::cin >> quit_game_or_continue;
		if (quit_game_or_continue == 'c')
		{
			while (1)
			{
				std::cout << std::endl << "Enter column number between 0 and 6 inclusive." << std::endl;
				std::cin >> human_entered_column_number;
				if ((human_entered_column_number >= 0 && human_entered_column_number < board_columns) && 
					check_if_empty_position(human_entered_column_number))
					break;
			}
		}
		else
		{
			game_complete = true;
		}
	}

	void Board::generate_machine_input()
	{
		while (1)
		{
			machine_entered_column_number = 0 + (rand() % 6);
			if (check_if_empty_position(machine_entered_column_number))
				break;
		}
	}

	bool Board::check_if_empty_position(int column_number)
	{
		for (int i = board_rows - 1; i >= 0; --i)
		{
			if (board[i][column_number] == 'W')
				return true;
		}
		return false;
	}

	void Board::mark_position_on_board(char ch, int column_number)
	{
		for (int i = board_rows - 1; i >= 0; --i)
		{
			if (board[i][column_number] != 'W')
				continue;
			if (board[i][column_number] == 'W')
			{
				board[i][column_number] = ch;
				break;
			}
		}
	}

	void Board::select_position_on_board()
	{
		if ((turn == human_player) && (human_player == player_and_result::yellow))
		{
			mark_position_on_board('Y', human_entered_column_number);
		}
		else if ((turn == human_player) && (human_player == player_and_result::red))
		{
			mark_position_on_board('R', human_entered_column_number);
		}
		else if ((turn == machine_player) && (machine_player == player_and_result::yellow))
		{
			mark_position_on_board('Y', machine_entered_column_number);
		}
		else if ((turn == machine_player) && (machine_player == player_and_result::red))
		{
			mark_position_on_board('R', machine_entered_column_number);
		}
	}

	// Print the board
	void Board::print_board()
	{
		if (board.empty())
			return;

		std::cout << std::endl;

		for (size_t i = 0; i < board_rows; ++i)
		{
			for (size_t j = 0; j < board_columns; ++j)
			{
				std::cout << " " << board[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}


	// Check if the board contains four connected disks either in a row, or,
	// either, horizontally, vertically, or diagonally
	void Board::check_for_connected_disks()
	{
		result = player_and_result::game_not_complete;

		for (size_t i = 0; i < board_rows; ++i)
		{
			for (size_t j = 0; j < board_columns; ++j)
			{
				//Check the horizontal connections first
				if (j + 3 < board_columns)
				{
					if (board[i][j] == 'Y' && board[i][j + 1] == 'Y' && board[i][j + 2] == 'Y' && board[i][j + 3] == 'Y')
					{
						result = player_and_result::yellow;
						game_complete = true;
						break;
					}
					if (board[i][j] == 'R' && board[i][j + 1] == 'R' && board[i][j + 2] == 'R' && board[i][j + 3] == 'R')
					{
						result = player_and_result::red;
						game_complete = true;
						break;
					}
				}

				//Check the vertical connections
				if (i + 3 < board_rows)
				{
					if (board[i][j] == 'Y' && board[i + 1][j] == 'Y' && board[i + 2][j] == 'Y' && board[i + 3][j] == 'Y')
					{
						result = player_and_result::yellow;
						game_complete = true;
						break;
					}
					if (board[i][j] == 'R' && board[i + 1][j] == 'R' && board[i + 2][j] == 'R' && board[i + 3][j] == 'R')
					{
						result = player_and_result::red;
						game_complete = true;
						break;
					}
				}

				//Check the diagonal connections from bottom left to top right
				if (i > 2 && j + 3 < board_columns)
				{
					if (board[i][j] == 'Y' && board[i - 1][j + 1] == 'Y' && board[i - 2][j + 2] == 'Y' && board[i - 3][j + 3] == 'Y')
					{
						result = player_and_result::yellow;
						game_complete = true;
						break;
					}
					if (board[i][j] == 'R' && board[i - 1][j + 1] == 'R' && board[i - 2][j + 2] == 'R' && board[i - 3][j + 3] == 'R')
					{
						result = player_and_result::red;
						game_complete = true;
						break;
					}

				}

				//Check the diagonal connections from top left to bottom right
				if (i + 3 < board_rows && j + 3 < board_columns)
				{
					if (board[i][j] == 'Y' && board[i + 1][j + 1] == 'Y' && board[i + 2][j + 2] == 'Y' && board[i + 3][j + 3] == 'Y')
					{
						result = player_and_result::yellow;
						game_complete = true;
						break;
					}
					if (board[i][j] == 'R' && board[i + 1][j + 1] == 'R' && board[i + 2][j + 2] == 'R' && board[i + 3][j + 3] == 'R')
					{
						result = player_and_result::red;
						game_complete = true;
						break;
					}

				}

			}//end of inner for loop

			if (game_complete)
				break;
		}

		if (game_complete)
			return;

		//This is set to true to unset later if the game is not complete
		//else it would be a draw
		game_complete = true;
		
		for (size_t i = 0; i < board_rows; ++i)
		{
			for (size_t j = 0; j < board_columns; ++j)
			{
				if (board[i][j] == 'Y' || board[i][j] == 'R')
					continue;

				if (board[i][j] == 'W')	//game not yet complete
				{
					game_complete = false;
					break;
				}
			}
			if (!game_complete)
				break;
		}
		
		//The game is complete and it is a draw
		if (game_complete)
			result = player_and_result::draw;

	}

	void Board::run_game()
	{
		while (1)
		{
			char ch;
			std::cout << std::endl << "Choose a colour to play - Press Y or y for Yellow or R or r for Red." << std::endl;
			std::cin >> ch;

			if (ch == 'Y' || ch == 'y')
			{
				human_player = player_and_result::yellow;
				machine_player = player_and_result::red;
				break;
			}
			else if (ch == 'R' || ch == 'r')
			{
				human_player = player_and_result::red;
				machine_player = player_and_result::yellow;
				break;
			}
		}

		turn = human_player;

		while (1)
		{
			if (turn == player_and_result::yellow)
			{
				if (human_player == player_and_result::yellow)
				{
					take_human_input();
				}
				else
				{
					generate_machine_input();
				}

				if (quit_game_or_continue == 'c')
				{
					select_position_on_board();
					print_board();
					check_for_connected_disks();
				}

				if (is_game_complete())
					break;
				turn = player_and_result::red;
			}
			else if (turn == player_and_result::red)
			{
				if (human_player == player_and_result::red)
				{
					take_human_input();
				}
				else
				{
					generate_machine_input();
				}

				if (quit_game_or_continue == 'c')
				{
					select_position_on_board();
					print_board();
					check_for_connected_disks();
				}

				if (is_game_complete())
					break;
				turn = player_and_result::yellow;
			}

		}

	}


}//end of namespace connect_four