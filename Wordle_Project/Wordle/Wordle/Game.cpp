#include "Game.h"

Game::Game()
{
}
Game::~Game()
{
}

char Game::setWordle(string word) // for testing, put l;ines 12, 19 and 20 back in.
{
	//cout << "The word is " << word << endl;
	for (int i = 0; i <= 4; i++)
	{
		wordle[i] = word[i];
	}
	for (int i = 0; i <= 4; i++) // testing purposes - to see the word before hand Suzy please take out the comment signs
	{
	//	cout << "letter " << i + 1 << " - ";
	//	cout << wordle[i] << endl;

	}
	return wordle[4];
}
string Game::getWordle()
{
	srand(time(0));
	string wordle;
	int lineNumber = rand() % 541 + 1;// generate random numbers for what line on the text file to sele
//	cout << "\nFor testing purposes, line number = " << lineNumber << endl;
	ifstream inStream;


	if (lineNumber <= 0 || lineNumber > 541)
	{
		cout << "There is no word on this line of the txt file" << endl;
	}
	inStream.open("wordList.txt");
	if (inStream.fail())
	{
		cout << " The file has failed to open correctly";
		exit(1); //ends the program }
	}

	int currentLine = 0;
	string line;

	while (!inStream.eof())
	{
		currentLine++;
		getline(inStream, line);
		if (currentLine == lineNumber)
		{
		//	cout << line;
			return line;
			break;
		}
	}
	if (currentLine < lineNumber)
	{
		cout << "Word not found!\n";
		cout << "File contains " << currentLine;
		cout << "lines total." << endl;

	}
	else cout << "Line: " << line << endl;

	inStream.close();
	return line;

}
void Game::guess(string a, int b)
{
	
	bool letterGuessedAfter = false; bool letterGuessedBefore = false;
	char correctLetter = 'x'; // stored as a lower case x because  x occurs less in words and all letters use capitals - it's a safe palceholder
	int letterLocation = 6;
							  // if they guess something that isn't a letter

	cout << "  # Guess number : " << b + 1 << endl;

	cout << "  #                  ";
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == wordle[i]) // if letter location matches wordle letter location
		{
			Game::changeColour("BLUE");
		}

		else if (a[i] != wordle[0] && a[i] != wordle[1] && a[i] != wordle[2] && a[i] != wordle[3] && a[i] != wordle[4]) // if the guess matches nowhere in the word, mark as grey
		{
			Game::changeColour("GREY");
		}
		else if (a[i] == wordle[0] || a[i] == wordle[1] || a[i] == wordle[2] || a[i] == wordle[3] || a[i] == wordle[4]) // if the letter matches another letter in the word
		{
			Game::changeColour("GREY");
			char repeatedLetter = Game::duplicateFinder();
			if (a[i] != repeatedLetter)
			{
				Game::changeColour("YELLOW");
			}
				

			if (Game::wordChecker() == false) // if the word does not have two letters that are the same
			{
				Game::changeColour("GREY");
				if (a[i] != wordle[i]) // to get into this original else if, the letter cannot be the same place, but the above paramenters of the else if mean I have to double check the letter does not match teh exact place of the wordle
				{
					//cout << "101";
					Game::changeColour("YELLOW");
				}
				for (int j = i + 1; j < 5; j++)
				{
					if (a[i] == wordle[j])
					{
						if (wordle[j] == a[j])
						{ // cycle through wordle to check if the guessed letter matches a word that has been correctly guessed later in the word (in a word where there are no duplicate letters)
							Game::changeColour("GREY");
						}
					}
				}
				
				if (i > 0) // check if a guess happened earlier, won't work in first part of the array because if you check a previous element in the array you will be out the scoppe and cause memory issue
				{
					for (int z = 0; z < i; z++)
					{
						if (a[i] == a[z]) // if the letter matches a previous guess
						{
							Game::changeColour("GREY");
							//break;
						}
					}
				}
			}
			//  -- wordchecker is true (wordle has two letters that are the same in a word) // this may need to be a function -- 
			else 
			{
				char repeatedLetter = Game::duplicateFinder();
				bool previousGuess = FALSE;
				// if a[i] != duplicateLetter and a[i] != previous guess or != a correct guess
				if (a[i] != repeatedLetter)
				{
					for (int r = 0; r < i; r++)
					{
						if (a[r] == a[i]) // if a previous guess a[r] matches a[i]
						{
							Game::changeColour("GREY");
							//cout << "&";
							previousGuess = TRUE;
						}
					}
					if (previousGuess == FALSE)
					{
						for (int q = 4; q > i; q--)
						{
							if (wordle[q] == a[i])
							{
								//cout << "^";
								Game::changeColour("grey");
							}
						}
					}
				}
				if (a[i] == repeatedLetter)
				{
					int g = 1; // variable to count how many times - start at one because if the letters match as above, there is already one letter matching (which arrays won't reach)AM
					int h = 0;
					int o = 0;

					for (int a = 0; a < 5; a++)
					{
						if (wordle[i] == repeatedLetter)
						{
							h++; // CALCULATE HOW MANY TIMES A LETTER IS DUPLICATED
						}
					}



					for (int y = 4; y > i; y--) // used to be y = 5 but this caused erros

					{
						if (a[i] == repeatedLetter) // if a duplicate letter has been guessed three times then incorrect third guess
						{
							g = 1; h = 0; o = 0;
							for (int z = 0; z < i; z++) // check if duplicate letter has occured before the current guess
							{
								if (a[z] == repeatedLetter) //
								{
									g++; // how many times the duplicate letter has been guessed
								}
							}
							for (int x = 4; x > i; x--) // how many times after the guess the letter occurs
							{
								if (a[x] == repeatedLetter)
								{
									o++;
								}
							}
						}
					}
					if (g > 1)
					{
						if (g > 2) // used to be g is greater than 1
						{

							Game::changeColour("GREY");
							
							
						}
						else if (g + o > h)
						{
							//cout << "!k";
							Game::changeColour("GREY");
						}
						else if (h - g == 1)
						{
							//cout << "!";
							Game::changeColour("YELLOW");
						}
						else if (o >= h)
						{
							//cout << "*";
							Game::changeColour("GREY");
						}
						else if (g + o < h)
						{
							//cout << "]]";
							Game::changeColour("YELLOW");
						}
						else if (h - g <= 1)
						{
							//cout << "(";
							Game::changeColour("GREY");
						}
						else
						//	cout << ")";
						Game::changeColour("grey");
						//g = 1; h = 0;
					}
				}
			}
		}
		else
		{
			Game::changeColour("YELLOW");
		}	

		cout << a[i];
		Game::changeColour("WHITE");
		if (i < 5)
		{
			cout << " | "; // display purposes
		}
	}

	cout << "                           # \n";
	char g1 = a[0];
	char g2 = a[1];
	char g3 = a[2];
	char g4 = a[3];
	char g5 = a[4];
	winnerCheck(g1, g2, g3, g4, g5);
}

char Game::duplicateFinder()
{
	for (int e = 0; e < 5; e++)
	{
		for (int f = 0; f < 5; f++)
		{
			if (wordle[e] == wordle[f] && e != f) // if it matches with another letter in the word that is not it's own 
			{
				char matchingLetter = wordle[e];
				return matchingLetter;
			}
		}
	}
}


bool Game::wordChecker() 
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (wordle[i] == wordle[j])
			{
				return true;
			}
		}
	}
	return false;
}

void Game::winnerCheck(char g1, char g2, char g3, char g4, char g5)
{
	if (g1 == wordle[0])
	{
		if (g2 == wordle[1])
		{
			if (g3 == wordle[2])
			{
				if (g4 == wordle[3])
				{
					if (g5 == wordle[4])
					{
						gameover = TRUE; //cout << "Congratulations!";
					}
				}
			}
		}
	}
}

void Game::changeColour(string colour)
{
	if (colour == "blue" || colour == "BLUE")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3); //Aqua
	}
	else if (colour == "yellow" || colour == "YELLOW")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 6); //Yellow
	}
	else if (colour == "grey" || colour == "GREY")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8); //Grey
	}
	else if (colour == "white" || colour == "WHITE")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7); //White
	}
	else // default colour will be white
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7); //White
	}
}
void Game::changeColour()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7); //White
}

bool Game::getGameover()
{
	return gameover;
}