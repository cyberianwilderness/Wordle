#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Interface.h"
#include <limits>
#include <cstdlib>
#include <random>
using namespace std;

class Game
{
private:
	
	char wordle[5] = { 'B','L','A','N','K' };
	bool gameover = FALSE;
public:
	Game();
	~Game();
	char setWordle(string);
	string getWordle();
	void guess(string, int);
	void winnerCheck(char, char, char, char, char);
	void changeColour(string);
	void changeColour();
	bool getGameover();
	bool wordChecker();
	char duplicateFinder();
	//char duplicateFinder(char, char, char, char, char);
};
