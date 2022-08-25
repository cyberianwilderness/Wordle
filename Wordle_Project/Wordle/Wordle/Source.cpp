/*
--- SPARE CODE/NOTES I MAY NEED IN THE FUTURE

/*Wordle

The game Wordle has become very popular and was recently bought by the New York Times.This has inspired spin offs including Heardleand Quordle.

For this task you should develop a text based game of Wordle which reads in a series of 5 letter words from a text file, stores these and then selects one word at random.

The user should then be prompted to enter in a 5 letter word guess and the game should then output in some format whether this was correct or incorrect and if correct if the letter is in the correct position.You can choose to do this in anyway you like – the LaMothe work from CMP 104 may be one option.

Once the user has entered the correct word a message should be outputted to the screen.

Likely concepts to be included :

Reading from a file

String manipulation

Array searching

User validation

Once you have the basic game working you can look at enhancements such as improvements to the UI or more challenging words.
*/

//	1 - Read word from file, selecting the number using random generator
//	2 - User inserts a guess
//		2.1 - Check there are 5 letters
//			2.1.1 - Check it is a word from the dictionary
//		2.2 - Extrapolate each letter from the guess (array)
//			2.2.1 - Check if any letters are in the correct place
//			2.2.2 - Check if letters are in the wrong place
//			2.2.3 - Alert users if letter is in the right place
//			2.2.4 - Alert user if letter is right and in the wrong place
//			2.2.5 - Alert user that letter is in the wrong place
//		3 - Track number of guesses user has had and stop after 5 guesses


/*
  --- TAKEN FROM GAME.CPP Game::guess function 
   if the letter has been guessed twice correctly



else if (a[i] == repeatedLetter)
				{
					for (int r = 0; r < i; r++)
					{
						if (a[r] == a[i]) // if a previous guess a[r] matches a[i]
						{
							Game::changeColour("GREY");
						}
					}
					for (int q = 4; q > i; q--)
					{
						if (a[q] == a[i])
						{
							Game::changeColour("GREY");
						}
					}
				}
				
				// if a[i] == duplicateLetter, and duplicate letter has been guessed twice in the future - grey
				// if a[i] == duplicateLetter, and duplicate letter has already been guessed twice - grey
				// if a[i] == duplicateLetter and the no previous guesses include this letter, yellow

				// // if a[i] == duplicateLetter and one previous guess include this letter, yellow
				// if a[i] == duplicateLetter and two previous guesses contain this letter grey
				// if a[i] == duplicateLetter and the two toher guesses are both correct, grey
				// if 
				//		if 


				//if (a[i] != wordle[i]) // to get into this original else if, the letter cannot be the same place, but the above paramenters of the else if mean I have to double check the letter does not match teh exact place of the wordle
				//{
				//	Game::changeColour("YELLOW");
				//	cout << "1";
				//}
				// THE PROBLEM IS IF THE LETTER OCCURS AFTER A CORRECT GUESS AND IF IT OCCURS BEFORE TWO CORRECT GUESSES
//				if (i > 1)
//				{
//					for (int z = 0; z < i; z++)
//					{
//						//if (a[i] == repeatedLetter &&  a[i] == a[z])
//						if (a[i] == repeatedLetter && a[z] == repeatedLetter)
//							// if a duplicate letter has been guessed three times then incorrect third guess
//						{
//							//if ()
//						//	cout << "2";
//							Game::changeColour("GREY");
//							
//						}
//						
//					}
//				}

-----------------------------------------------------------------------

*/