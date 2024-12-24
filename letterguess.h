#pragma once
//header file for letterguess with a vector Player list
#define LETTERGUESS_H

#include <iostream>
#include <string>
#include <vector> //vector class

using namespace std;


struct Player
{
	string name;
	bool wonOrLost = 0;
	char currentGuess = 0;
	char solution = 0;
};



class letterguess
{
public:
	//constructor
	letterguess();

	void UpdatePlayerCount(int); //updates the player count
	int GetPlayerCount()const; //returns the player count

	void SetUpRound(ifstream& in); //sets up a round of the game
	void PlayOneRound(); //play a round of the game

	void PrintGameResults(); //prints the player, wonOrLost on the screen


private:

	void GetNextGuess(); //gets the next guess from the user
	bool ProcessGuess(); //determines if the guess is right or wrong

	bool guessTooLow;
	bool guessTooHigh;

	vector<Player>playerList;//vector of players
	int count;//number of players
	int maxGuesses;//max number of guesses
};


