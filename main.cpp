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


int main()
{
	char ch;

	std::cout << std::endl << "Do you want to run the Connect Four game? (Y/y)" << std::endl;
	std::cin >> ch;

	if (ch == 'Y' || ch == 'y')
	{
		connect_four::Board connect_four_game_board;

		connect_four_game_board.PrintBoard();

		connect_four_game_board.RunGame();

		connect_four::result result;
		connect_four::player winner;

		if (connect_four_game_board.IsGameQuitted())
		{
			std::cout << std::endl << "Game quitted." << std::endl;
		}
		else if (connect_four_game_board.IsGameComplete())
		{
			result = connect_four_game_board.GetResult();
			winner = connect_four_game_board.GetWinner();

			if (result == connect_four::result::won)
			{
				if (winner == connect_four::player::yellow)
				{
					std::cout << std::endl << "Yellow is the Winner." << std::endl;
				}
				else if (winner == connect_four::player::red)
				{
					std::cout << std::endl << "Red is the Winner." << std::endl;
				}
			}
			else if (result == connect_four::result::draw)
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
