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

#include <string>
#include <random>

#include "Board.h"


namespace connect_four
{
	Board::Board()
		: human_player(player::yellow),
		  machine_player(player::red),
		  turn(player::yellow),
		  winner(player::yellow),
		  result(result::game_not_complete),
		  game_complete(false),
		  game_quitted(false)
	{
	}

	bool Board::IsGameComplete() const
	{
		return game_complete;
	}

	bool Board::IsGameQuitted() const
	{
		return game_quitted;
	}

	result Board::GetResult() const
	{
		return result;
	}

	player Board::GetWinner() const
	{
		return winner;
	}

	// Print the board
	void Board::PrintBoard() const
	{
		std::cout << std::endl;

		for (int i = 0; i < connect_four::board_rows; ++i)
		{
			for (int j = 0; j < connect_four::board_columns; ++j)
			{
				std::cout << " " << board[i][j] << " ";
			}

			std::cout << std::endl;
		}
	}


	int Board::TakeHumanInput()
	{
		int human_entered_column_number = 0;

		std::cin >> human_entered_column_number;
		if ( !(human_entered_column_number >= board_column_num_min
			&& human_entered_column_number <= board_column_num_max) 
			//the column number is reduced by 1, since column indexing starts from 0
			|| !CheckIfEmptyPosition(human_entered_column_number - 1) )
		{
			game_quitted = true;
		}

		return human_entered_column_number;
	}


	int Board::GenerateMachineInput()
	{
		int machine_entered_column_number = 0;
		std::uniform_int_distribution<> temp{ 1, 7 };
		std::default_random_engine engine;

		while (1)
		{
			//experimenting with two options for generating random numbers
			
			//machine_entered_column_number = 1 + (rand() % 7);
				
			machine_entered_column_number = temp(engine);

			//the column number is reduced by 1, since column indexing starts from 0
			if (CheckIfEmptyPosition(machine_entered_column_number - 1))
				break;
		}

		return machine_entered_column_number;
	}


	bool Board::SetPositionAndCheck(player turn, int column_number)
	{
		bool position_marked = MarkPositionOnBoard(turn, column_number);
		if (!position_marked)
		{
			return position_marked;
		}

		PrintBoard();
		CheckForConnectedDisks();

		return position_marked;
	}


	bool Board::CheckIfEmptyPosition(int column_number) const
	{
		for (int i = board_rows - 1; i >= 0; --i)
		{
			if (board[i][column_number] == 'W')
				return true;
		}
		return false;
	}

	bool Board::MarkPositionOnBoard(player turn, int column_number)
	{
		bool valid_position = false;
		char ch = yellow;

		if (turn == player::yellow)
		{
			ch = yellow;
		}
		else if (turn == player::red)
		{
			ch = red;
		}

		for (int i = board_rows - 1; i >= 0; --i)
		{
			if (board[i][column_number] != white)
				continue;
			if (board[i][column_number] == white)
			{
				board[i][column_number] = ch;
				valid_position = true;
				break;
			}
		}

		return valid_position;
	}

	// Check if the board contains four connected disks either in a row, or,
	// either, horizontally, vertically, or diagonally
	void Board::CheckForConnectedDisks()
	{
		result = result::game_not_complete;

		std::pair<int, int> first_position;
		std::pair<int, int> second_position;
		std::pair<int, int> third_position;
		std::pair<int, int> fourth_position;


		for (int i = 0; i < board_rows; ++i)
		{
			for (int j = 0; j < board_columns; ++j)
			{
				//Check the horizontal connections first
				if (j + 3 < board_columns)
				{
					first_position.first = i;
					first_position.second = j;
					second_position.first = i;
					second_position.second = j + 1;
					third_position.first = i;
					third_position.second = j + 2;
					fourth_position.first = i;
					fourth_position.second = j + 3;

					if (CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, yellow)
					  || CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, red) )
					{
						break;
					}
				}

				//Check the vertical connections
				if (i + 3 < board_rows)
				{
					first_position.first = i;
					first_position.second = j;
					second_position.first = i + 1;
					second_position.second = j;
					third_position.first = i + 2;
					third_position.second = j;
					fourth_position.first = i + 3;
					fourth_position.second = j;

					if (CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, yellow)
						|| CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, red))
					{
						break;
					}
				}

				//Check the diagonal connections from bottom left to top right
				if (i > 2 && j + 3 < board_columns)
				{
					first_position.first = i;
					first_position.second = j;
					second_position.first = i - 1;
					second_position.second = j + 1;
					third_position.first = i - 2;
					third_position.second = j + 2;
					fourth_position.first = i - 3;
					fourth_position.second = j + 3;

					if (CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, yellow)
						|| CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, red))
					{
						break;
					}
				}

				//Check the diagonal connections from top left to bottom right
				if (i + 3 < board_rows && j + 3 < board_columns)
				{
					first_position.first = i;
					first_position.second = j;
					second_position.first = i + 1;
					second_position.second = j + 1;
					third_position.first = i + 2;
					third_position.second = j + 2;
					fourth_position.first = i + 3;
					fourth_position.second = j + 3;

					if (CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, yellow)
						|| CheckConnectedDisksAndMarkWinner(first_position, second_position, third_position, fourth_position, red))
					{
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
		
		for (int i = 0; i < board_rows; ++i)
		{
			for (int j = 0; j < board_columns; ++j)
			{
				if (board[i][j] == yellow || board[i][j] == red)
					continue;

				if (board[i][j] == white)	//game not yet complete
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
			result = result::draw;

	}

	bool Board::CheckConnectedDisksAndMarkWinner(const std::pair<int, int>& first_position, const std::pair<int, int>& second_position,
		const std::pair<int, int>& third_position, const std::pair<int, int>& fourth_position, char color)
	{
		game_complete = false;

		if ( (board[first_position.first][first_position.second] == color)
			&& (board[second_position.first][second_position.second] == color)
			&& (board[third_position.first][third_position.second] == color)
			&& (board[fourth_position.first][fourth_position.second] == color))
		{
			if (color == yellow)
			{
				winner = player::yellow;
			}
			else if (color == red)
			{
				winner = player::red;

			}
			result = result::won;
			game_complete = true;
		}

		return game_complete;
	}

	void Board::RunGame()
	{
		while (1)
		{
			char ch;
			std::cout << std::endl << "Choose a colour to play - Press Y or y for Yellow or R or r for Red." << std::endl;
			std::cin >> ch;

			if (ch == yellow || ch == yellow_small)
			{
				human_player = player::yellow;
				machine_player = player::red;
				break;
			}
			else if (ch == red || ch == red_small)
			{
				human_player = player::red;
				machine_player = player::yellow;
				break;
			}
			else
			{
				std::cout << std::endl << "Invalid input. " << std::endl;
			}
		}

		turn = human_player;

		std::cout << std::endl << "For your turn, enter column number between 1 and 7 inclusive." << std::endl;
		std::cout << std::endl << "If you want to quit the game, at any point, press any other key, during your turn." << std::endl;


		while (1)
		{
			bool position_marked = false;

			if (turn == human_player)
			{
				while (1)
				{
					int human_entered_column_number = TakeHumanInput();
					if (IsGameQuitted())
						break;

					//the column number is reduced by 1, since column indexing starts from 0
					position_marked = SetPositionAndCheck(turn, human_entered_column_number - 1);
					if (!position_marked)
					{
						continue;
					}
					else
					{
						break;
					}
				}

				if (IsGameQuitted())
					break;

				turn = machine_player;
			}
			else if (turn == machine_player)
			{
				while (1)
				{
					int machine_entered_column_number = GenerateMachineInput();
					//the column number is reduced by 1, since column indexing starts from 0
					position_marked = SetPositionAndCheck(turn, machine_entered_column_number - 1);

					if (!position_marked)
					{
						continue;
					}
					else
					{
						break;
					}
				}

				turn = human_player;
			}

			if (IsGameComplete())
				break;
		}

	}


}//end of namespace connect_four
