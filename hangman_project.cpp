//This is a hangman game project written in C++ 
//Created by Maria Kalendarova

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

const int MAX_TRIES = 6;

string randomize()
{
	vector<string> words 
	{
	"speech","policy","camera","depth", 
	 "silver","limited","agency","volume", 
	 "gesture","coffee","black","scene", 
	 "unit","flight","ladder","hunter", 
	 "college","engine","animal","network",
	 "hangman","channel","chimney","routine"
	 }; 
	
	srand(time(0));									
	string& random_word = words[rand() % words.size()]; 
 	return random_word;
	
}//randomize


char read_letter()
{
	cout << "Enter a letter: ";
	char letter;
	cin >> letter;
	
	return letter;
}//readletter

string reveal_letter_in_word(string word, string mystery_word, char letter)
{
	for(int i = 0; i < word.size(); i++)
	{
		if(letter == word[i])
		{
			mystery_word[i] = letter;
		}
	}
	
	return mystery_word;
}//reveal_letter

void drawing_the_man(int tries, string random_word)
{
	switch(tries)
 			{
 				case 1: 
 				{
 					cout << "You have 5 more tries" << endl;
 					cout << " |----| " << endl;
 				
 					break;
 				}
 				case 2:
 				{
 					cout << "You have 4 more tries" << endl;
					cout << " |----| " << endl;
					cout << " |    O "  << endl;
					
 					break;
 				}
 				case 3:
 				{
 					cout << "You have 3 more tries" << endl;
 					cout << " |----| " << endl;
					cout << " |    O "  << endl;
					cout << " |    | "  << endl;	
 					
					break;
				}
				case 4:
				{	
					cout << "You have 2 more tries" << endl;
					cout << " |----| " << endl;
					cout << " |    O "  << endl;
					cout << " |    | "  << endl;
 					cout << " |  \\ | / " << endl;
 					
 					break;
 				}	
 				case 5:
 				{	
 					cout << "You have only one more try" << endl;
 					cout << " |----| " << endl;
					cout << " |    O "  << endl;
					cout << " |    | "  << endl;
 					cout << " |  \\ | / " << endl;
					cout << " |    |   " << endl;
					
					break;
				}
				case 6:
				{
					cout << " |----| " << endl;
					cout << " |    O "  << endl;
					cout << " |    | "  << endl;
 					cout << " |  \\ | / " << endl;
					cout << " |    |   " << endl;
 					cout << " |   / " "\\ " << endl;
 					cout << "GAME OVER, you don't have more attemps! Sorry, better luck next time!" << "The word was: " << random_word << endl;
 				}
 			}
}//void

int main()
{
	cout << "We are playing Hangman! You have " << MAX_TRIES << " attemps to guess your word!" << endl << "Don't repeat the letters you've already tried to guess because it will cost you more tries!" << endl << endl;
	
	string random_word = randomize();
	string mystery_word(random_word.length(), '*'); //replaces the letters with *	
	cout << "This is your word: " << mystery_word << endl;
	// cout << random_word << endl; - to see the random_word in advance
	
	int tries = 0;
	
	while (tries < MAX_TRIES)
	{
		char letter = read_letter(); 
		string hidden_word = reveal_letter_in_word(random_word, mystery_word, letter);
		cout << hidden_word << endl;
		
	 	if(hidden_word == random_word)
		{
			cout << "CONGRATS! You've guessed the word - " << random_word << endl;
		 	break;
		}
		if(mystery_word == hidden_word)
		{
		 	cout << "Wrong letter, try again! " << endl;
		 	tries++;
		 	drawing_the_man(tries,random_word);
		}
		    
		else
		{
		 	mystery_word = hidden_word;
		 	cout << "Right guess!" << endl;
		}
		
	}//while
	
	return 0;
	
}//main
