#include <iostream>
#include<exception>
#include<cstring>

void GetWords(char* string, char* words[], int& counter) {
    char* simbol = string;
    while (*simbol != '\0')
    {
        while (*simbol == ' ')
        {
            ++simbol;
        }
        if (*simbol == '\0')
        {
            break;
        }
           
        words[counter] = simbol;
        ++counter;

        while (*simbol != ' ' && *simbol != '\0')
        {
            ++simbol;
        }
            
        if (*simbol == ' ')
        {
            *simbol = '\0';
            ++simbol;
        }
    }
}

bool IsEmpty(char* str)
{
    return str[0] == '\0';
}

bool OnlyDelimeters(char* str)
{
    bool checking = 1;
    for (size_t i{}; str[i] != '\0'; ++i)
    {
        if (isalnum(str[i]))
        {
            checking = 0;
        }
    }
    return checking;
}

int main() {
    const int32_t maxLenght = 1000;
    const int32_t maxWords = 100;
    char firstString[maxLenght];
    char secondString[maxLenght];
    char* resultWords[2 * maxLenght];


    std::cout << "Input 1st string: \n";
    std::cin.getline(firstString, maxLenght);

    std::cout << "Input 2nd string: \n";
    std::cin.getline(secondString, maxLenght);
    std::cout << "\n\n";

    char* firstWordsAdress[maxWords];
    char* secondWordsAdress[maxWords];
    int32_t firstCounter = 0;
    int32_t secondCounter = 0;

    try
    {
        if (IsEmpty(firstString) && IsEmpty(secondString))
        {
            throw std::invalid_argument("Is empty!\n");
        }
        if (OnlyDelimeters(firstString) && OnlyDelimeters(secondString))
        {
            throw std::invalid_argument("Only delimeters!\n");
        }

        GetWords(firstString, firstWordsAdress, firstCounter);
        GetWords(secondString, secondWordsAdress, secondCounter);




        int32_t maxCount{};
        if (firstCounter > secondCounter)
        {
            maxCount = firstCounter;
        }
        else
        {
            maxCount = secondCounter;
        }

        int32_t resultCounter{};

        for (size_t i = 0; i < maxCount; ++i) {
            if (i < firstCounter) {
                resultWords[resultCounter] = const_cast<char*>(firstWordsAdress[i]);
                ++resultCounter;
            }
            if (i < secondCounter) {
                resultWords[resultCounter] = const_cast<char*>(secondWordsAdress[i]);
                ++resultCounter;
            }
        }

        bool firstPrinted = false;

        for (size_t i{}; i < resultCounter; ++i) {
            if (firstPrinted)
            {
                std::cout << " ";
            }
            std::cout << resultWords[i];
            firstPrinted = true;
        }

        std::cout << '\n';
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}