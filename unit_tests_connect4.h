#pragma once
/*******************************************************************/
/* Unit Tests Header file - unit_tests_connect4.h */

/* Connect Four Game */

/* Description */

/* Connect Four(or Vier op een rij in Dutch) is a two - player connection board game, in         */
/* which the players choose a colorand then take turns dropping colored discs into a             */
/* seven-column, six-row, vertically suspended grid.The pieces fall straight down, occupying     */
/* the lowest available space within the column.The objective of the game is to be the first to  */
/* form a horizontal, vertical, or diagonal line of four of one's own discs. If the board fills  */
/* up before either player achieves four in a row, then the game is a draw.                      */
/*  Reference to the Game - in the following links                                               */
/* https://www.helpfulgames.com/subjects/brain-training/connect-four.html						 */
/* https://www.cbc.ca/kids/games/all/connect-4													 */

/* Author - Anind Duttaroy */
/*******************************************************************/

#include "Board.h"

namespace connect_four
{
	namespace unit_tests
	{

		class unit_tests_connect4
		{
		public:
			void run_unit_tests();
		private:
			void test_horizontal_connection();
			void test_vertical_connection();
			void test_connection_from_bottom_left_to_top_right();
			void test_connection_from_top_left_to_bottom_right();

		};

	}//end of namespace unit_tests
}//end of namespace connect_four
