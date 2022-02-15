#include <iostream>
#include <windows.h>
#include <ctime>

void PlayIntroduction(int PatientNo)
{
	std::cout << ".............. \n";
	std::cout << "You are now treating patient no " << PatientNo-1 << "\n";
	std::cout << ".............. \n";
}

bool PlayGame(int LevelDifficulty,int Chances)
{
	
	PlayIntroduction(LevelDifficulty);
	int NutritionA = rand()% LevelDifficulty+ LevelDifficulty;
	int NutritionB = rand()% LevelDifficulty+ LevelDifficulty;
	int NutritionC = rand()% LevelDifficulty+ LevelDifficulty;
	bool bWonRound;

	int NutritionSum = NutritionA + NutritionB + NutritionC;
	int NutritionProduct = NutritionA * NutritionB * NutritionC;

	int GuessA;
	int GuessB;
	int GuessC;
	int GuessSum;
	int GuessProduct;

	std::cout << "There are 3 numbers to figure out" << "\n";
	std::cout << "------------- \n";
	std::cout << "Sum of the 3 Nutrition are " << NutritionSum << "\n";
	std::cout << "------------- \n";
	std::cout << "Product of the 3 Nutrition are " << NutritionProduct << "\n";
	std::cout << "------------- \n";
	std::cout << "Enter First Suggestion" << "\n";
	std::cin >> GuessA;
	std::cout << "Enter Second Suggestion" << "\n";
	std::cin >> GuessB;
	std::cout << "Enter Third Suggestion" << "\n";
	std::cin >> GuessC;

	GuessSum = GuessA + GuessB + GuessC;
	GuessProduct = GuessA * GuessB * GuessC;
	//std::cout << "You Have Entered -->" << GuessA<<", " << GuessB << ", " << GuessC << "." << "\n";
	std::cout << "Sum of the 3 Guesses are " << GuessSum << "\n";
	std::cout << "Product of the 3 Guesses are " << GuessProduct << "\n";

	if ((GuessSum == NutritionSum) && (GuessProduct == NutritionProduct))
	{
		std::cout << "You have suggested the correct nutritions the patient survived" << std::endl;
		PlaySound(TEXT("ArcadeGameWon.wav"), NULL, SND_FILENAME | SND_ASYNC);
		bWonRound = true;
		system("pause");
		

	}
	else {
		Chances--;
		std::cout << "Your suggestion was wrong. \nThe Patient Died." << std::endl;
		std::cout << "You have total " << Chances << " chances left." << "\n";
		bWonRound = false;
		PlaySound(TEXT("gameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("pause");
	}
	return bWonRound;

}

int main()
{
	
	int LevelDifficulty = 2;
	int MaxDifficulty = 5;
	int Chances = 3;
	bool Play = true;
	PlaySound(TEXT("ArcadeGameStart.wav"), NULL, SND_FILENAME | SND_ASYNC);
	std::cout << "Hello you are a new Doctor.You have started Your practice recently" << "\n";
	std::cout << "You will be given product value of three numbers representing the product value of the nutritions needed for the patients." << "\n";
	std::cout << "You will be given summation value of three numbers representing the summation value of the nutritions needed for the patients." << "\n";
	std::cout << "Your task is to give your nurse combination of three numbers based on the summation and product of nutrition patients needed ." << "\n";
	std::cout << "This combination of numbers will tell your nurse which medicine you want to prescribe to the patients." << "\n";
	std::cout << "If you give wrong prescriptions the patient will die and you will lose your licence" << "\n";
	srand(time(NULL));

	while (Play)
	{
		if (Chances>0&& LevelDifficulty<MaxDifficulty)
		{
			std::cout << "You have total " <<Chances <<" chances." << "\n";
			Play = PlayGame(LevelDifficulty, Chances);
			std::cin.clear();
			std::cin.ignore();
			if (!Play)
			{
				--Chances;
				Play = true;
			}
			else {
				LevelDifficulty++;
			}
		}
		else
		{
			Play = false;
			if (LevelDifficulty == MaxDifficulty)
			{
				std::cout << "You are now a Master Doctor Congratulations. You Have Won " << "\n";
			}
		}
		
	}
	

	return 0;		
}