#include "pch.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;


void sum(int, int);
bool craps(int, int, int, int&, int&, int);
int main()
{
	srand(time(NULL));
	int Dice1, Dice2, Points = 0, Win = 0, Loss = 0, stuff, X, Temp = 0;

	cout << "Press any key to roll and click enter: ";
	cin >> stuff;
	cout << endl;
	//	for (int games = 0; games <= 10000; games++)
	//	{
	Dice1 = rand() % 6 + 1;
	Dice2 = rand() % 6 + 1;

	cout << endl;
	cout << "Your first dice is: " << Dice1 << endl;
	cout << "Your second dice is: " << Dice2 << endl;
	sum(Dice1, Dice2);
	bool hold = craps(Dice1, Dice2, Points, Loss, Win, Temp);

	while (hold)
	{
		Dice1 = rand() % 6 + 1;
		Dice2 = rand() % 6 + 1;
		cout << endl;
		cout << "Your first dice is: " << Dice1 << endl;
		cout << "Your second dice is: " << Dice2 << endl;
		X = Dice1 + Dice2;
		cout << "The sum of your roll is: " << X << endl;
		cout << endl;
		if (X == 7)
		{
			Loss++;
			cout << "You Lose!" << endl;
			break;
		}
		else if (Points == X)
		{
			Win++;
			cout << "You Win!" << endl;
			break;
		}

	}
	cout << endl;
	cout << "Number of games played: " << games << endl;
	cout << "Number of wins: " << Win << endl;
	cout << "Number of losses: " << Loss << endl;
	//	}
	int toast;
	toast = Win / Loss;
	cout << "Probability of winning: " << toast << endl;
	return 0;
}
void sum(int Dice1, int Dice2)
{
	cout << "The sum of your rolls is:" << Dice1 + Dice2 << endl;
}

bool craps(int Dice1, int Dice2, int Points, int& Loss, int& Win, int Temp)
{
	Temp = Dice1 + Dice2;

	if (Temp == 2 || Temp == 3 || Temp == 12)
	{
		Loss++;
		cout << "You lose!" << endl;
		return false;
	}
	else if (Temp == 7 || Temp == 11)
	{
		Win++;
		cout << "You win!" << endl;
		return false;
	}
	else
	{
		Points = Temp;
		cout << "Your points are: " << Points << endl;
		return true;
	}
}