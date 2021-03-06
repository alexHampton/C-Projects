// Author: Alex Hampton


#include <iostream>
using namespace std;

int main()
{
	char playAgain('y');

	do
	{
		int sticks(23), playerNum, computerNum;
		cout << "Let's play a game of \"23\"!\n";

		while (sticks > 0)
		{
			/***************************************
			/*            PLAYER INPUT             *
			/***************************************/

			if (sticks == 23)													// Ask for a number.
				cout << "Enter the number of sticks you wish to pick: ";
			else
				cout << "Your turn. Enter the number of sticks you wish to pick: ";

			do
			{
				cin >> playerNum;
				if (playerNum < 1 || playerNum > 3)								// Handle input errors.
				{
					cout << "Wrong number of sticks. Please pick 1, 2, or 3 sticks: ";
				}
				else if (playerNum > sticks)
					cout << "There are not that many sticks left. Try again: ";
			} while (playerNum < 1 || playerNum > 3 || playerNum > sticks);



			sticks -= playerNum;											// subtract from sticks.

			cout << "You picked " << playerNum << " stick";
			if (playerNum > 1)										// Pluralize text if more than 1 stick.
				cout << "s";
			cout << ". " << sticks << " left.\n";


			if (sticks <= 0)											// End game if 0 sticks remaining.
			{
				cout << "\nYou picked the last stick.\n"
					<< "Computer wins!\n\n";
				cout << "Do you want to play another game? <Y/N>: ";	// Prompt player to play again.
				cin >> playAgain;
				break;
			}


			/***************************************
			/*           COMPUTER LOGIC            *
			/***************************************/
			if (sticks > 4)					// In cases where sticks are more than 4. 
			{
				computerNum = 4 - playerNum;
			}

			else if (sticks >= 1 && sticks <= 4)
			{
				switch (sticks)				// In cases where sticks are less than 4.
				{
				case 1:
				case 2:
					computerNum = 1;
					break;
				case 3:
					computerNum = 2;
					break;
				case 4:
					computerNum = 3;
					break;
				default:
					cout << "There is an error with the computer logic\n";
				}
			}

			sticks -= computerNum;
			cout << "Computer picked " << computerNum << " stick";	
			if (computerNum > 1)									// Pluralize text if more than 1 stick.
				cout << "s";
			cout << ". " << sticks << " left.\n\n";

			if (sticks <= 0)										// End game if 0 sticks remaining.
			{
				cout << "\nComputer picked the last stick.\n"
					<< " You win!\n\n";
				cout << "Do you want to play another game?<Y/N>: ";	// Prompt player to play again.
				cin >> playAgain;							
			}


		}

	} while (playAgain == 'Y' || playAgain == 'y');

	return 0;
	
}




/***************************************
/*           SAMPLE OUTPUT             *
/***************************************/


/*	Let's play a game of "23"!
	Enter the number of sticks you wish to pick: 4
	Wrong number of sticks. Please pick 1, 2, oe 3, sticks: 1
	You picked 1 stick. 22 left.
	Computer picked 3 sticks. 19 left.

	Your turn. Enter the number of sticks you wish to pick: 2
	You picked 2 sticks. 17 left.
	Computer picked 2 sticks. 15 left.

	Your turn. Enter the number of sticks you wish to pick: 3
	You picked 3 sticks. 12 left.
	Computer picked 1 stick. 11 left.

	Your turn. Enter the number of sticks you wish to pick: 3
	You picked 3 sticks. 8 left.
	Computer picked 1 stick. 7 left.

	Your turn. Enter the number of sticks you wish to pick: 3
	You picked 3 sticks. 4 left. 
	Computer picked 3 sticks. 1 left.

	Your turn. Enter the number of sticks you wish to pick: 2
	There are not that many sticks left. Try again: 1
	You picked 1 stick. 0 left.

	You picked the last stick.
	Computer wins!

	Do you want to play another game? <Y/N>: y
	Let's play a game of "23"!
	Enter the number of sticks you wish to pick:1
	..................2

	*/