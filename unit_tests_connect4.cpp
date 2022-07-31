/*******************************************************************/
/* Unit Tests Implementation file - unit_tests_connect4.cpp */

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

#include "unit_tests_connect4.h"


namespace connect_four
{
	namespace unit_tests
	{
		/************************************************************************************/
		//Unit Test to test function check_for_connected_disks() for horizontal connection
		/************************************************************************************/
		void unit_tests_connect4::test_horizontal_connection()
		{
			std::vector<std::vector<char>> board1 =
			{
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'Y', 'Y', 'Y', 'Y' },

			};

			player_and_result result;

			connect_four::Board connect_four_game_board;

			connect_four_game_board.set_board(board1);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}


			std::vector<std::vector<char>> board2 =
			{
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'R', 'R', 'R', 'R', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },

			};

			connect_four_game_board.set_game_complete_status(false);
			connect_four_game_board.set_board(board2);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}


		}

		/************************************************************************************/
		//Unit Test to test function check_for_connected_disks() for vertical connection
		/************************************************************************************/
		void unit_tests_connect4::test_vertical_connection()
		{
			std::vector<std::vector<char>> board1 =
			{
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'Y', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'Y', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'Y', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'Y', 'W', 'W', 'W', 'W', 'W' },

			};

			player_and_result result;

			connect_four::Board connect_four_game_board;

			connect_four_game_board.set_board(board1);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}


			std::vector<std::vector<char>> board2 =
			{
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'R' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'R' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'R' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'R' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'Y' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'Y' },

			};

			connect_four_game_board.set_game_complete_status(false);
			connect_four_game_board.set_board(board2);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}


		}

		/************************************************************************************/
		//Unit Test to test function check_for_connected_disks() for diagonal connection
		//from bottom left to top right
		/************************************************************************************/
		void unit_tests_connect4::test_connection_from_bottom_left_to_top_right()
		{
			std::vector<std::vector<char>> board1 =
			{
				{ 'W', 'W', 'W', 'W', 'R', 'W', 'W' },
				{ 'W', 'W', 'W', 'R', 'W', 'W', 'W' },
				{ 'W', 'W', 'R', 'W', 'W', 'W', 'W' },
				{ 'W', 'R', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },

			};

			player_and_result result;
			connect_four::Board connect_four_game_board;

			connect_four_game_board.set_board(board1);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == connect_four::player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}


			std::vector<std::vector<char>> board2 =
			{
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'Y' },
				{ 'W', 'W', 'W', 'W', 'W', 'Y', 'W' },
				{ 'W', 'W', 'W', 'W', 'Y', 'W', 'W' },
				{ 'W', 'W', 'W', 'Y', 'W', 'W', 'W' },

			};

			connect_four_game_board.set_game_complete_status(false);
			connect_four_game_board.set_board(board2);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}

		}

		/************************************************************************************/
		//Unit Test to test function check_for_connected_disks() for diagonal connection
		//from top left to bottom right
		/************************************************************************************/
		void unit_tests_connect4::test_connection_from_top_left_to_bottom_right()
		{
			std::vector<std::vector<char>> board1 =
			{
				{ 'W', 'W', 'Y', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'Y', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'Y', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'Y', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },

			};

			player_and_result result;
			connect_four::Board connect_four_game_board;

			connect_four_game_board.set_board(board1);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}


			std::vector<std::vector<char>> board2 =
			{
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
				{ 'R', 'W', 'W', 'W', 'W', 'W', 'Y' },
				{ 'W', 'R', 'W', 'W', 'W', 'Y', 'W' },
				{ 'W', 'W', 'R', 'W', 'Y', 'W', 'W' },
				{ 'W', 'W', 'W', 'R', 'W', 'W', 'W' },

			};

			connect_four_game_board.set_game_complete_status(false);
			connect_four_game_board.set_board(board2);
			connect_four_game_board.print_board();
			connect_four_game_board.check_for_connected_disks();

			if (connect_four_game_board.is_game_complete())
			{
				result = connect_four_game_board.get_result();
			}

			if (result == player_and_result::yellow)
			{
				std::cout << "Yellow is the Winner." << std::endl;
			}
			else if (result == player_and_result::red)
			{
				std::cout << "Red is the Winner." << std::endl;
			}
			else if (result == connect_four::player_and_result::draw)
			{
				std::cout << "It is a Draw." << std::endl;
			}

		}

		void unit_tests_connect4::run_unit_tests()
		{
			//Run Unit Tests
			std::cout << std::endl << "Unit Test testing horizontal connection." << std::endl;
			test_horizontal_connection();

			std::cout << std::endl << "Unit Test testing vertical connection." << std::endl;
			test_vertical_connection();

			std::cout << std::endl << "Unit Test testing connection from bottom left to top right." << std::endl;
			test_connection_from_bottom_left_to_top_right();

			std::cout << std::endl << "Unit Test testing connection from top left to bottom right." << std::endl;
			test_connection_from_top_left_to_bottom_right();

		}

	}//end of namespace unit_tests
}//end of namespace connect_four