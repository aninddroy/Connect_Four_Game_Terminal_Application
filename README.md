Notes to look into, for the Connect Four Game application. (by Anind Duttaroy)
Connect Four (or Vier op een rij in Dutch) is a two - player connection board game, in which the players choose a color and then take turns dropping colored discs into a seven-column, six-row, vertically suspended grid. The pieces fall straight down, occupying the lowest available space within the column. The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs. If the board fills up before either player achieves four in a row, then the game is a draw.
Reference to the Game - in the following links :-
https://www.helpfulgames.com/subjects/brain-training/connect-four.html
https://www.cbc.ca/kids/games/all/connect-4

1.	The accompanying files are – main.cpp, Board.h, Board.cpp

2.	Main.cpp includes Board.h 

3.	The files have been compiled on Microsoft Visual Studio 2022 compiler, on Windows. The files does not contain any Microsoft Windows specific code.

4.	The game runs successfully on Windows, in the terminal.

5.	When the main program is run, the user is asked the option if the user wants to run the game.

6.	If the user presses Y or y, the game is run giving the user the option to choose the color.

7.	Then the user is asked to select a column number, since this is a vertical board game, only the column number is needed, to fill in from the bottom.

8.	After each turn the board is printed on the terminal. At each turn the user is asked to select a column number.

9.	The user may quit the game, by selecting a different key during his/her turn.

10.	The board initially consists of 7 columns and 6 rows of W in each position.

11.	Then it is filled with Y or R, standing for Yellow or Red.

12.	When there is a vertical, horizontal or diagonal line of four of discs (in this case R or W letters), that particular color is the winner.

13.	It is possible for the user to win against the machine, since, for the machine, very simple random number generation is used.

14.	It took about 4-5 hours to think the design and write the code, though I did not do that at a stretch.
