#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"
#include "Game.h"
#include <string>
using namespace std;


// to do list
// use POINTERS
// have the alphabet with letters greyed out
// get the word to be able to check if the letter that has bene guessed appears more than twice in a word, then check if it matches any, then put yellow or blue, then if the letter has been guessed three times, one must be greyed out that is not in the correct position.
// if there are double letters, don't have it going blue then yellow e.g. guessing treat and the would is chant - the first t would be yellow and the second blue
//
int main()
{
	// -- classes --
	class Interface Interface;
	class Game Wordle;

	// -- attributes --
	bool gameover = FALSE;
	string guess = "GUESS"; string word;

	Interface.openingHeader();
	Interface.rules();
	

//	Interface.loserMessage("CRANE"); // the word crane will be changed with what ever the 5 letter word is
//	Interface.winnerMessage("CRANE");


	//while (gameover != TRUE)
	//{

	//}

	word = Wordle.getWordle();
	Wordle.setWordle(word);
	Wordle.wordChecker();



	for (int i = 0; i < 6; i++)
	{
		if (Wordle.getGameover() != TRUE)
		{
			guess = Interface.gameUI();
			//cin >> guess;
			Wordle.guess(guess, i);
		}
		if (Wordle.getGameover() == TRUE)
		{
			Interface.winnerMessage(guess);
			break;
		}
	}
	if (Wordle.getGameover() != TRUE)
	{
		Interface.loserMessage(word);
	}
	cout << "Thanks for playing! Did you enjoy it? : ";
		string response;
	cin >> response;
	return 0;
}
