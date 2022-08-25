#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <windows.h>
#include <string.h>

class Interface
{
private:
	char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
public:
	string verticalBorder = "  ###################################################################\n";
	string horizontalBorder = "  #                                                                 #\n";
	string centreAlignPartOne = "  #                      | ";
	string centreAlignPartTwo = " |                      #\n";

	Interface();
	~Interface();
	void rules();
	void letterStatus();
	void alphabet();
	void winnerMessage(string);
	void loserMessage(string);
	void openingHeader();
	string gameUI();
	void changeColour(string);
	void changeColour();

	//char A = 'A'; char B = 'B'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A';
	//char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A';
	//char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A'; char A = 'A';
};

