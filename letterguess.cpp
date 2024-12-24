//cpp file for the number game
#include <iostream> // library for i/o
#include <string>
#include <fstream>
#include <vector>
#include "letterguess.h"

using namespace std;

//constructor
letterguess::letterguess()
{
	cout << "The default constructor has been called\n";

}


//updates the player count mutator function
void letterguess::UpdatePlayerCount(int playerCount)
{
	count = playerCount;
}

//returns the player count accessor function
int letterguess::GetPlayerCount()const
{
	//return the count
	return count;
}


void letterguess::SetUpRound(ifstream& in)
//Description:  get user's name and prepare program for the next round
{
	Player currentPlayer;

	cout << "\nSetting up a new round of the letter guess game!";
	cout << "\nThe game allows multiple players, will keep score, and post the results at the end";
	cout << "\nEnter your first name: ";
	cin >> currentPlayer.name; // get player's name

	in >> currentPlayer.solution; //letter from the file
	currentPlayer.currentGuess = '\0'; //reset the current guess
	currentPlayer.wonOrLost = 0;

	guessTooLow = 0;
	guessTooHigh = 0;
	maxGuesses = 6;

	playerList.push_back(currentPlayer); //add the player to the player list

}

void letterguess::PlayOneRound()
//Description:  process the round of letter guess game
{
	guessTooLow = 0;
	guessTooHigh = 0;
    
        // tell user how many guesses they have
	cout << playerList[count].name << " You will have " << maxGuesses << " guesses, Good Luck!" << endl;


	for (int i = 0; i < maxGuesses; i++)
	{

		cout << "\nThis is guess number (" << i + 1 << ")";
		GetNextGuess(); //member function | get next guess from player
		guessTooLow = 0; //reset values for new guess
		guessTooHigh = 0;
		if (ProcessGuess()) // check if guess is correct
		{
			cout << "\nYou won that round, " << playerList[count].name << "!\n"; //use the vector as an array
			playerList[count].wonOrLost = 1; //set wonOrlost to true
			//break out of the loop without a break statment
			return;
		}
	}
    // processes if player did not win
	cout << "\nYou did not win that round, " << playerList[count].name << "!\n";
	cout << "\nTHE SOLUTION WAS '" << playerList[count].solution << "'" << endl;

}


void letterguess::GetNextGuess()
//Description:  tell user if their guess was too low or too high, ask for next guess
{
	if (guessTooLow) // guessTooLow = 1
	{
		cout << "\nEnter a guess alphabetically above '" << playerList[count].currentGuess << "' : ";
	} else if (guessTooHigh) { // guessTooHigh = 1
        cout << "\nEnter a guess alphabetically below '" << playerList[count].currentGuess << "': ";
    } else { // ask for the first guess
        cout << "\nEnter a guess: ";
    }

	cin >> playerList[count].currentGuess;  // get user's guess
}

bool letterguess::ProcessGuess()
//Description:  process the guess the user entered
{
	if (playerList[count].currentGuess == playerList[count].solution) // if guess is correct
		return true;
	else if (playerList[count].currentGuess > playerList[count].solution) // if guess is higher than solution
	{
		cout << "\nYour guess was too high.";
		cout << "\n-----------------------";
		guessTooHigh = true;
	} else {                                // if guess is lower than solution
        cout << "\nYour guess was too low.";
        cout << "\n-----------------------";
        guessTooLow = true;
    }
    return false; // guess is incorrect
	
}

void letterguess::PrintGameResults()
//Description:  print results for all players
{
	//prints results on the screen
	cout << "**************************************************\n";
	cout << "Name:\t" << "Won or Lost:\n";
	//for loop for printing on the screen.
	for (int i = 0; i < count; i++)
	{
        cout << playerList[i].name << "\t" << (playerList[i].wonOrLost ? "1" : "0") << "\n"; // print name and result
	}
}
