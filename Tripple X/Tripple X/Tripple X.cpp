#include <iostream>
#include <ctime>

using namespace std;

void Printintroduction(int Difficulty) {
	cout << "You are a secret agent breaking into a level " <<Difficulty << endl;
	cout << " secure server room...\nEnter the correct code to continue...\n" << endl;
}

bool PlayGame(int Difficulty) {
	
	Printintroduction(Difficulty);
	//Declare 3 number codes
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	// Print Sum and Product to the terminal
	cout << "There are 3 lines in the code \n" << endl;
	cout << "\nThe codes add up to " << CodeSum << endl;
	cout << "\nthe codes multiply to " << CodeProduct << endl;

	//store player guess
	int GuessA, GuessB, GuessC;
	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;
	cout << "You entered: " << GuessA << GuessB << GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// check to see if player guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
		cout << "\nYou win!\n";
		return true;
	}
	else {
		cout << "\nYou lose!";
		return false;
	}

}

int main() {

	srand(time(NULL));//creates a new random sequence based on time of day

	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) // loops untill all levels are completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear();//Clears any Errors
		cin.ignore();//discards the buffer

		if (bLevelComplete)
		{
			//increase the level difficulty
			++LevelDifficulty;
		}
	}
	return 0;
}