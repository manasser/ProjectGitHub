#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <time.h> 

using namespace std;

class NamePick {

public:

	string GetName();

};

string NamePick::GetName()
{
	string characterName;
	cout << "Please pick a name for your Human Figher." << endl;
	cout << "Your name: ";
	cin >> characterName;
	
	return characterName;
}


class AbilityScoreBuy {

public:

	int BuyAbility();
	int DiceRoll();
	int GetMinScore(int a, int b, int c, int d);
	void AssignValuesBought(int sumTotal);

};

int AbilityScoreBuy::DiceRoll()
{
	int scoreTotal = 0;
	int sumTotal = 0;
	int minScore = 0;
	
	//int diceValue;
	//int die[4]; //the values of each dice contained in an array
	string roll;
	int dice1, dice2, dice3, dice4;
	//AbilityScoreBuy asb;

	for(int i = 0; i < 6; i++) //roll 4 die 6 times
	{
		dice1 = dice2 = dice3 = dice4; //reinitialize the values of the die for each iteration (roll)
		cout << "Type 'roll' to roll the set of die number " << (i+1) << "." << endl;
		cin >> roll;
	
		/*for(int i = 0; i < 4; i++)
		{
			diceValue = rand() % 6 + 1;
			die[i] = diceValue;

		}*/

		srand(time(NULL));
		dice1 = rand() % 6 + 1; //a random value between 1 and 6
		cout << dice1 << endl;
		dice2 = rand() % 6 + 1;
		cout << dice2 << endl;
		dice3 = rand() % 6 + 1;
		cout << dice3 << endl;
		dice4 = rand() % 6 + 1;
		cout << dice4 << endl;

		scoreTotal = dice1 + dice2 + dice3 + dice4;
		cout << "The total for this set of die is: " << scoreTotal << endl;

		/*for(int i = 0; i < 4; i++)
		{
			cout << die[i] << endl;
		}*/

		minScore = GetMinScore(dice1, dice2, dice3, dice4);

		cout << "The minimum score of the roll was: " << minScore << "." << endl;
		cout << "Therefore, " << minScore << " will be deducted from " << scoreTotal << "." << endl;
		scoreTotal -= minScore;
		cout << "The total score of the roll is: " << scoreTotal << "." << endl;
		sumTotal += scoreTotal;
		cout << "The total score so far is: " << sumTotal << "." << endl;
		//asb.GetMinScore(die);
	}

	return sumTotal;

}

int AbilityScoreBuy::BuyAbility()
{
	int sumTotal = 0;
	string characterName;
	
	//int diceValue;
	//int die[4]; //the values of each dice contained in an array

	//AbilityScoreBuy asb;

	NamePick np;

	characterName = np.GetName();

	cout << "\n\n\n";
	cout << "This is the Ability Scores Buy." << endl;
	cout << "In this part, you will roll 4 Six-Sided dice 6 times." << endl;
	cout << "After each roll, we will discard the lowest die result, and add the three remaining results together." << endl; 
	cout << "We will record this total and repeat the process until six numbers are generated." << endl;

	sumTotal = DiceRoll();

	AssignValuesBought(sumTotal);
	
	return sumTotal;
}

int AbilityScoreBuy::GetMinScore(int a, int b, int c, int d)
{
	cout << "This is the get min score function" << endl;
	cout << "The 4 values were: " << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;

	if(a <= b)
	{
		if(a <= c)
		{
			if(a <= d)
			{
				cout << "The lowest value is: " << a << endl;
				return a;
			}
		}
		else
		{
			if(c <= d)
			{
				cout << "The lowest value is: " << c << endl;
				return c; 
			}
			else
			{
				cout << "The lowest value is: " << d << endl;
				return d;
			}
		}
	}
	else
	{
		if(b <= c)
		{
			if(b <= d)
			{
				cout << "The lowest value is: " << b << endl;
				return b;
			}
		}
		else
		{
			if(c <= d)
			{
				cout << "The lowest value is: " << c << endl;
				return c;
			}
			else
			{
				cout << "The lowest value is: " << d << endl;
				return d;
			}
		}
	}

}

void AbilityScoreBuy::AssignValuesBought(int sumTotal)
{
	string str = "Strength", cha = "Charisma", dex = "Dexterity";
	string wis = "Wisdom", intel = "Intelligence", cons = "Constitution";
	string choiceArea;
	int choicePoints;
	int sumTotalTemp=sumTotal; //incase of a restart
	int strPoints=0, chaPoints=0, dexPoints=0, wisPoints=0, intelPoints=0, consPoints=0;
	string choiceRestart;

	cout << "\n\n\n";
	cout << "This is where we assign values generated." << endl;
	cout << "The amount of points you have to distribute is: ";
	cout << sumTotal << "." << endl;

	cout << "The points will be distributed amongst the following areas: " << endl;
	cout << "Strength, Wisdom, Charisma, Dexterity, Intelligence, Constitution." << endl;
	cout << "Each area will contain a range of values between the minimum 3, and the maximum 18." << endl;

	bool i = false;

	while(i==false) //to test whether the critera have been met (each area between 3 and 18), if not, restart
	{
		sumTotal = sumTotalTemp; 
		int strPoints=0, chaPoints=0, dexPoints=0, wisPoints=0, intelPoints=0, consPoints=0; //incase of a restart
		while(sumTotal > 0) //until the player runs out of points
		{
			cout << "\n\n\n";
			cout << "Your current stats are: " << endl;
			cout << "Strength: " << strPoints << " /18" << endl;
			cout << "Charisma: " << chaPoints << " /18" << endl;
			cout << "Dexterity: " << dexPoints << " /18" << endl;
			cout << "Wisdom: " << wisPoints << " /18" << endl;
			cout << "Intelligence: " << intelPoints << " /18" << endl;
			cout << "Constitution: " << consPoints << " /18" << endl;

			cout << "\n\n\n";
			cout << "\nYou have " << sumTotal << " points remaining." << endl;
			cout << "Which area would you like to add points?" << endl;
			cout << "Your pick: ";
			cin >> choiceArea;
			cout << "How many points would you like to add?" << endl;
			cin >> choicePoints;

			if(choiceArea == str)
			{
				sumTotal -= choicePoints;
				
				if(sumTotal >= 0) //to test whether there are enough points left
				{
					strPoints += choicePoints;
					
					if(strPoints <= 18)
					{
						cout << "Strength points added." << endl;
					}
					else //if the points in a given area excedes 18
					{
						cout << "\n\n";
						cout << "Sorry, the maximum points per area is 18." << endl;
						cout << "Please try again." << endl;
						strPoints -= choicePoints; //remove the points that were to be added
						sumTotal += choicePoints;
						continue;
					}
				}
				else //if sumTotal falls below 0
				{
					cout << "Sorry, you do not have enough points for that move." << endl;
					cout << "Please try again." << endl;
					sumTotal += choicePoints; //re-add the points that were meant to be deducted
					continue;
				}
			}

			else if(choiceArea == cha)
			{

				sumTotal -= choicePoints;
				
				if(sumTotal >= 0) //to test whether there are enough points left
				{
					chaPoints += choicePoints;
					
					if(chaPoints <= 18)
					{
						cout << "Charisma points added." << endl;
					}
					else
					{
						cout << "\n\n";
						cout << "Sorry, the maximum points per area is 18." << endl;
						cout << "Please try again." << endl;
						chaPoints -= choicePoints; //remove the points that were to be added
						sumTotal += choicePoints;
						continue;
					}
				}
				else 
				{
					cout << "Sorry, you do not have enough points for that move." << endl;
					cout << "Please try again." << endl;
					sumTotal += choicePoints; //re-add the points that were meant to be deducted
					continue;
				}
			}

			else if(choiceArea == dex)
			{

				sumTotal -= choicePoints;
				
				if(sumTotal >= 0) //to test whether there are enough points left
				{
					dexPoints += choicePoints;
					
					if(strPoints <= 18)
					{
						cout << "Dexterity points added." << endl;
					}
					else
					{
						cout << "\n\n";
						cout << "Sorry, the maximum points per area is 18." << endl;
						cout << "Please try again." << endl;
						dexPoints -= choicePoints; //remove the points that were to be added
						sumTotal += choicePoints;
						continue;
					}
				}
				else
				{
					cout << "Sorry, you do not have enough points for that move." << endl;
					cout << "Please try again." << endl;
					sumTotal += choicePoints; //re-add the points that were meant to be deducted
					continue;
				}
			}

			else if(choiceArea == wis)
			{

				sumTotal -= choicePoints;

				if(sumTotal >= 0) //to test whether there are enough points left
				{
					wisPoints += choicePoints;
					
					if(wisPoints <= 18)
					{
						cout << "Wisdom points added." << endl;
					}
					else
					{
						cout << "\n\n";
						cout << "Sorry, the maximum points per area is 18." << endl;
						cout << "Please try again." << endl;
						wisPoints -= choicePoints; //remove the points that were to be added
						sumTotal += choicePoints;
						continue;
					}
				}
				else
				{
					cout << "Sorry, you do not have enough points for that move." << endl;
					cout << "Please try again." << endl;
					sumTotal += choicePoints; //re-add the points that were meant to be deducted
					continue;
				}
			}

			else if(choiceArea == intel)
			{
			
				sumTotal -= choicePoints;
				if(sumTotal >= 0) //to test whether there are enough points left
				{
					intelPoints += choicePoints;
					
					if(intelPoints <= 18)
					{
						cout << "Intelligence points added." << endl;
					}
					else
					{
						cout << "\n\n";
						cout << "Sorry, the maximum points per area is 18." << endl;
						cout << "Please try again." << endl;
						intelPoints -= choicePoints; //remove the points that were to be added
						sumTotal += choicePoints;
						continue;
					}
				}
				else
				{
					cout << "Sorry, you do not have enough points for that move." << endl;
					cout << "Please try again." << endl;
					sumTotal += choicePoints; //re-add the points that were meant to be deducted
					continue;
				}
			}

			else if(choiceArea == cons)
			{
				
				sumTotal -= choicePoints;

				if(sumTotal >= 0) //to test whether there are enough points left
				{
					consPoints += choicePoints;
					
					if(consPoints <= 18)
					{
						cout << "Constitution points added." << endl;
					}
					else
					{
						cout << "\n\n";
						cout << "Sorry, the maximum points per area is 18." << endl;
						cout << "Please try again." << endl;
						consPoints -= choicePoints; //remove the points that were to be added
						sumTotal += choicePoints;
						continue;
					}
				}
				else
				{
					cout << "Sorry, you do not have enough points for that move." << endl;
					cout << "Please try again." << endl;
					sumTotal += choicePoints; //re-add the points that were meant to be deducted
					continue;
				}
			}
			
			else
			{
				cout << "\n\n";
				cout << "You did not type in a correct area. Please type another one." << endl;
				cout << "\n";
				continue;
			}

			if(sumTotal > 0)
			{
				cout << "\nYou have " << sumTotal << " points remaining." << endl;
			}	
		}

		cout << "\n\n\n";
		cout << "You have finished buying stats for your character." << endl;
		cout << "Your final stats are: " << endl;
		cout << "Strength: " << strPoints << " /18" << endl;
		cout << "Charisma: " << chaPoints << " /18" << endl;
		cout << "Dexterity: " << dexPoints << " /18" << endl;
		cout << "Wisdom: " << wisPoints << " /18" << endl;
		cout << "Intelligence: " << intelPoints << " /18" << endl;
		cout << "Constitution: " << consPoints << " /18" << endl;

		cout << "Is this Okay?" << endl;
		cout <<"\n\nType 'Yes' to continue with these stats." << endl;
		cout <<"Otherwise, you can type 'No' to restart." << endl;
		cin >> choiceRestart;
		if(choiceRestart == "Yes")
		{
			i = true; //quit the loop
		}
		else
		{
			continue; //start over
		}

	}

}

/*int GetMinScore(int die[])
{
	cout << "This is the get min score function" << endl;	

}*/

/*class AssignValuesBuy {

public:

	void AssignValuesBought(int sumTotal);
	

};*/




class AbilityScoreRand {

public:

	void GenerateAbility();
	void RandomGenerator(int sumTotal);

};

void AbilityScoreRand::GenerateAbility()
{
	int sumTotal = 0;
	string characterName;
	
	//int diceValue;
	//int die[4]; //the values of each dice contained in an array

	AbilityScoreBuy asb;
	NamePick np;

	characterName = np.GetName();

	cout << "\n\n\n";
	cout << "This is the Ability Scores Random Generator." << endl;
	cout << "In this part, you will first roll 4 Six-Sided dice 6 times." << endl;
	cout << "After each roll, we will discard the lowest die result, and add the three remaining results together." << endl; 
	cout << "We will record this total and repeat the process until six numbers are generated." << endl;
	cout << "Finally, the ability scores will be generated for you randomly based on the total points rolled from the die." << endl;

	sumTotal = asb.DiceRoll();
	
	RandomGenerator(sumTotal);

}

void AbilityScoreRand::RandomGenerator(int sumTotal)
{
	int strPoints=0, chaPoints=0, dexPoints=0, wisPoints=0, intelPoints=0, consPoints=0;
	bool i = false;
	int sumTemp = sumTotal;
	int j=1;

	while(i==false)
	{
		int strPoints=0, chaPoints=0, dexPoints=0, wisPoints=0, intelPoints=0, consPoints=0; //incase of a restart
		sumTotal = sumTemp;
	
		//while(sumTotal > 0)
		//{
			//cout << "in the while" << endl;
			srand(time(NULL));
			strPoints = rand() % 16 + 3; //a random value between 3 and 18
			sumTotal -= strPoints;
			//strPoints += strPoints;
			//cout << "strPoints: " << strPoints << endl;

			chaPoints = rand() % 16 + 3;
			sumTotal -= chaPoints;
			//chaPoints += chaPoints;
			//cout << "chaPoints: " << chaPoints << endl;

			dexPoints = rand() % 16 + 3;
			sumTotal -= dexPoints;
			//dexPoints += dexPoints;
			//cout << "dexPoints: " << dexPoints << endl;

			wisPoints = rand() % 16 + 3;
			sumTotal -= wisPoints;
			//wisPoints += wisPoints;
			//cout << "wisPoints: " << wisPoints << endl;

			intelPoints = rand() % 16 + 3;
			sumTotal -= intelPoints;
			//intelPoints += intelPoints;
			//cout << "intelPoints: " << intelPoints << endl;

			consPoints = rand() % 16 + 3;
			sumTotal -= consPoints;
			//consPoints += consPoints;
			//cout << "consPoints: " << consPoints << endl;

			if(j==1)
			{
				cout << "Loading... " << endl; //to display loading once
				j=0;
			}
		//}
		
		if(sumTotal == 0) //if the points were divided up exactly
		{
			cout << "sumTotal: "<< sumTotal << endl;

			cout << "\n\n\n";
			cout << "The stats for your character have been randomly generated." << endl;
			cout << "Your final stats are: " << endl;
			cout << "Strength: " << strPoints << " /18" << endl;
			cout << "Charisma: " << chaPoints << " /18" << endl;
			cout << "Dexterity: " << dexPoints << " /18" << endl;
			cout << "Wisdom: " << wisPoints << " /18" << endl;
			cout << "Intelligence: " << intelPoints << " /18" << endl;
			cout << "Constitution: " << consPoints << " /18" << endl;

			i = true; //quit the loop
		}
		/*else
		{
			continue; //otherwise, we start over
		}*/

	}

}

int main()
{
	//NamePick np;
	//np.GetName();
	AbilityScoreBuy asb;
	AbilityScoreRand asr;
	string abilityChoice;
	string choiceBuy = "buy";
	string choiceGenerate = "generate";

	//bool i = false;

	cout << "You can either buy your ability scores or generate them randomly." << endl;
	cout << "Pick either 'buy' or 'generate'" << endl;

	//while((abilityChoice != choiceBuy) || (abilityChoice != choiceGenerate))
	//{
		cout << "Your pick: ";
		cin >> abilityChoice;

		if(abilityChoice == choiceBuy)
		{
			asb.BuyAbility();
			
		}

		if(abilityChoice == choiceGenerate)
		{
			asr.GenerateAbility();
		}

		//cout << "Please enter 'buy' or 'generate'" << endl;
	//}
	


	return 0;
}
