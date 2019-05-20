//preprocessor directive
#include <iostream> 

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room. \nYou need to enter the correct codes to continue...";
    std::cout << "\nThere are 3 numbers in the code.\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
   //declare 3 number code
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    //sum and product
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    std::cout << "\nSum: " << CodeSum;
    std::cout << "\nProduct: " << CodeProduct;

    //Store player guesses
    int GuessA;
    int GuessB;
    int GuessC;
    std::cout << "\n\nPlease enter your guess.\n";
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    std::cout << "\nSum: " << GuessA + GuessB + GuessC;
    std::cout << "\nProduct: " << GuessA * GuessB * GuessC;

    //check if player's guess is correct


    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou Win!";
        return true;
    }

    else
    {
        std::cout << "\nYou Lose!";
        return false;
    }
}

//main function
int main () 
{
    int LevelDifficulty=1;
    int MaxDifficulty = 10;
    while (LevelDifficulty<=MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //clears any errors
        std::cin.ignore(); //discards the buffer
        if (bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
    }
    return 0;
}