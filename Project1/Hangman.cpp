#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

const string WORD_LIST[] = { "dog", "cat", "human","version", "people"};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string fig(int badGuessCount);
string chooseWord();
void renderGame(string guessedWord, int badGuessCount);
string update(string &guessedWord, string secretWord, char guess);

int main()
{
	srand(time(0));
	char guess = 0;
	string secretWord = chooseWord();
	string guessedWord = string(secretWord.length(), '-');
	int badGuessCount = 0;
	renderGame(guessedWord, badGuessCount);

	do
	{
		cout << "Press your word: ";
		cin >> guess; guess = tolower(guess);
		if (secretWord.find(guess)!=string::npos)
		{
			update( guessedWord,  secretWord,  guess);
		}
		else 
		{
			badGuessCount++;
		}
		renderGame(guessedWord, badGuessCount);

		
	} while (badGuessCount < 7 && guessedWord != secretWord);
	



	return 0;
}

string chooseWord()
{
	int randomIndex = rand() % WORD_COUNT;
	return WORD_LIST[randomIndex];
}
string fig(int badGuessCount)
{
	const string FIGURE[] =
	{
		" ------------- \n"
		" | \n"
		" | \n"
		" | \n"
		" | \n"
		" | \n"
		" ----- \n",

		" ------------- \n"
		" |  | \n"
		" | \n"
		" | \n"
		" | \n"
		" | \n"
		" ----- \n",

		" ------------- \n"
		" |  | \n"
		" |  O \n"
		" | \n"
		" | \n"
		" | \n"
		" ----- \n",

		" ------------- \n"
		" |  | \n"
		" |  O \n"
		" |  | \n"
		" | \n"
		" | \n"
		" ----- \n",

		" ------------- \n"
		" |  | \n"
		" |  O \n"
		" | /| \n"
		" | \n"
		" | \n"
		" ----- \n",
		" ------------- \n"
		" |  | \n"
		" |  O \n"
		" | /|\\ \n"
		" | \n"
		" | \n"
		" ----- \n",

		" ------------- \n"
		" |  | \n"
		" |  O \n"
		" | /|\\ \n"
		" | / \n"
		" | \n"
		" ----- \n",
		" ------------- \n"
		" |  | \n"
		" |  O \n"
		" | /|\\ \n"
		" | / \\ \n"
		" | \n"
		" ----- \n"

	};
	return FIGURE[badGuessCount];

}
void renderGame(string guessedWord, int badGuessCount)
{
	system("cls");
	string man = fig(badGuessCount);
	cout << man << endl;
	cout << "...................................." << endl;
	cout << guessedWord << endl;
	cout << "Number of wrong guesses: " << badGuessCount << endl;
	
}
string update(string &guessedWord, string secretWord, char guess)
{
	for (int i = secretWord.size()-1; i >=0; i--)
	{
		if (secretWord[i] == guess)
		{
			guessedWord[i] = guess;
		}
	}
	return guessedWord;
}

