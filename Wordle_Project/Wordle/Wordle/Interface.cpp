#include "Interface.h"
#include <iostream>

Interface::Interface()
{
}
Interface::~Interface()
{
}


void Interface::openingHeader()
{
	Interface::changeColour(); // default colour to white

	cout << "  ###################################################################" << endl;
	cout << "  #                                                                 #" << endl;
	cout << "  #      ##       ##   ######  ######  ######  ##      #######      #" << endl;
	cout << "  #      ##       ##  ##    ## ##   ## ##   ## ##      ##           #" << endl;
	cout << "  #       ##  #  ##   ##    ## ######  ##   ## ##      #####        #" << endl;
	cout << "  #        ## # ##    ##    ## ##   ## ##   ## ##      ##           #" << endl;
	cout << "  #         ## ###     ######  ##   ## ######  ####### #######      #" << endl;
	cout << "  #                                                                 #" << endl;
	cout << "  ###################################################################" << endl;

}

void::Interface::letterStatus() // FUTURE IDEA
{
}
void::Interface::alphabet() // FUTURE IDEA
{
	 

	cout << "  ###################################################################" << endl;
	cout << "  #                                                                 #" << endl;
//	cout << "  #        A B C D E F G H I J K L M N O P Q R S T U V W X Y Z      #" << endl;
	Interface::changeColour();
	cout << "  #         Q    W    E    R    T    Y    U    I    O    P          #" << endl;
	cout << "  #            A    S    D    F    G    H    J    K    L            #" << endl;
	cout << "  #              Z    X    C    V    B    N    M                    #" << endl;
	cout << "  #                                                                 #" << endl;
	cout << "  ###################################################################" << endl;
}
void Interface::rules()
{
	string blue = "blue";		string yellow = "yellow";
	string grey = "grey";		string white = "white";

	cout << "  #                                                                 #" << endl;
	cout << "  # Welcome to world of Wordle!                                     #\n";
	cout << "  # Can you guess the wordle by guessing other 5 letter words?      #\n";
	cout << "  #                                                                 #" << endl;
	cout << "  # After each guess, your letters will change colour               #" << endl;
	cout << "  # A correct letter turns ";						Interface::changeColour(blue);	cout << "blue";		Interface::changeColour(white); cout << "                                     #" << endl;
	cout << "  # A correct letter in the wrong place turns ";	Interface::changeColour(yellow); cout << "yellow";	Interface::changeColour(white); cout << "                #" << endl;
	cout << "  # An incorrect letter turns ";					Interface::changeColour(grey);	cout << "grey";		Interface::changeColour(white); cout << "                                  #" << endl;
	cout << "  # You have 6 guesses to work out the hidden word, buena suerte!   #" << endl;
	cout << "  #                                                                 #" << endl;
	cout << "  ###################################################################" << endl;
	cout << "  #                                                                 #" << endl;
	cout << "  # Here is an example                                              #" << endl;
	cout << "  # If you guess the word 'GUESS' beneath is what you would see     #" << endl;
	cout << "  #                   ";
	Interface::changeColour(blue);
	cout << "G";
	Interface::changeColour(grey);
	cout << " | U | ";
	Interface::changeColour(yellow);
	cout << "E ";
	Interface::changeColour(grey);
	cout << "| S | S"; Interface::changeColour(white); cout << "                             # \n";
	cout << "  # G is correct, E appears elsewhere and U and S are incorrect     #\n";
	cout << "  # CAUTION: Guesses must use CAPITAL letters.                      #" << endl;
	cout << "  #                                                                 #" << endl;
	//cout << "  ###################################################################" << endl;
}

string Interface::gameUI()
{
	string guess;
	Interface::changeColour(); // may not be required
	cout << "  ###################################################################" << endl;
	cout << "  #                                                                 #" << endl;
	cout << "            Please enter your next guess: "; cin >> guess; 
	
	while (guess.length() != 5)
	{
		cout << "\n  # You're guess must contain 5 letters.                        #\n  # Please try again: ";
		cin >> guess;
	}
	//cout << "                             #B" << endl;
	cout << "  #                                                                 #" << endl;
	return guess;

}
void Interface::winnerMessage(string word)
{
	cout << horizontalBorder;
	cout << "  # Bravo! The word is indeed - " << word << " Suzy. Congratulations!        #\n";
	cout << horizontalBorder; 	cout << verticalBorder;
}
void Interface::loserMessage(string word)
{
	cout << horizontalBorder;
	cout << "  # You failed to guess the word - " << word << ". Please try again!         #\n";
	cout << horizontalBorder; cout << verticalBorder;

}
void Interface::changeColour(string colour)
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
void Interface::changeColour()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7); //White
}