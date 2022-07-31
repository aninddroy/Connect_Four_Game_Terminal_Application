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

Notes to look into. (by Anind Duttaroy) for the Connect Four Game application.
1.	The accompanying files are – main.cpp, Board.h, Board.cpp, unit_tests_connect4.h, and unit_tests_connect4.h.cpp

2.	Main.cpp includes Board.h and unit_tests_connect4.h

3.	unit_tests_connect4.h includes Board.h

4.	The files have been compiled on Microsoft Visual Studio 2019 compiler, on Windows. The files does not contain any Microsoft Windows specific code.

5.	The game runs successfully on Windows, in the terminal.

6.	 When the main program is run, it asks the user if the user wants to run unit tests.

7.	If yes, the unit tests are run, else not.

8.	After that, the user is asked the option if the user wants to run the game.

9.	If the user presses Y or y, the game is run giving the user the option to choose the color.

10.	Then the user is asked to select a column number, since this is a vertical board game, only the column number is needed to fill in from the bottom.

11.	After each turn the board is printed on the terminal. At each turn the user is asked to select a column number.

12.	The board initially consists of 7 columns and 6 rows of W in each position.

13.	Then it is filled with Y or R, standing for Yellow or Red.

14.	When there is a vertical, horizontal or diagonal line of four of discs (in this case R or W letters), that particular color is the winner.

15.	The unit tests written are for the function which checks for testing the horizontal, vertical or diagonal connections.

16.	So, more unit tests need to be written.

17.	It is possible to for the user to win against the machine, since for the machine only a random number generation, rand() function is used.

18.	It took about 4-5 hours to think the design and write the code, though I did not do that at a stretch.
