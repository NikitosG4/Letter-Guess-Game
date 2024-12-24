/*
By: Mykyta Garkusha
This is the Letter Guess Game. It saves game results with the player's name.
Game results will be printed when player chooses to stop playing the game.
*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <fstream>
#include "letterguess.h"

using namespace std;


//main function

int main()
{
	string yesOrNo = "y";

	ifstream in;

	//connecting to the input file:
	in.open("letters.txt");

	if (in.fail())
	{
		//did not find the file
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}

	//declaring an object of type letterguess
	letterguess activeGame;
    int gameCount = 0; //declare and set a game count to 0 for the array(vector) count


	cout << "Do you want to play the letter guessing game (we will only be guessing lowercase letters)? (y or n):  ";
	cin >> yesOrNo;

	while (yesOrNo != "n" && yesOrNo != "N")
	{
		//play one round
        activeGame.SetUpRound(in); // prepare new round
        activeGame.PlayOneRound(); // process the round

		gameCount++;
        activeGame.UpdatePlayerCount(gameCount); // update game count
		

		cout << "Do you want to play the another round? (y or n):  ";
		cin >> yesOrNo;
	}

	activeGame.PrintGameResults(); // print results for all players

	
	in.close(); // close file 

	return  0;
}






