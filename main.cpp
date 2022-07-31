/*******************************************************************/

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
#include "Board.h"
#include "unit_tests_connect4.h"


int main()
{
	char ch;

	std::cout << std::endl << "Do you want to run unit tests testing the ConnectFour board class functions? (Y/y)" << std::endl;
	std::cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		connect_four::unit_tests::unit_tests_connect4 unit_tests;
		unit_tests.run_unit_tests();
	}
	else
	{
		std::cout << std::endl << "Unit Tests not run" << std::endl;
	}

	std::cout << std::endl << "Do you want to run the Connect Four game? (Y/y)" << std::endl;
	std::cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		connect_four::Board connect_four_game_board;

		connect_four_game_board.print_board();

		connect_four_game_board.run_game();

		connect_four::player_and_result result;

		if (connect_four_game_board.is_game_complete())
		{
			result = connect_four_game_board.get_result();

			if (result == connect_four::player_and_result::yellow)
			{
				std::cout << std::endl << "Yellow is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::red)
			{
				std::cout << std::endl << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << std::endl << "It is a Draw." << std::endl;
			}

		}
	}
	else
	{
		std::cout << std::endl << "Connect Four game not run" << std::endl;
		return 0;
	}

	return 0;
}
