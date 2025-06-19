#include <iostream>
#include <string>
#include <cctype>

std::string ToLowerCase(const std::string& string) {
    std::string result = string;
    for (char& symbol : result) {
        if (symbol >= 'A' && symbol <= 'Z')
        {
            symbol += ('a' - 'A');
        }
    }
    return result;
}


int GetWords(const std::string& string, std::string words[], int maxSize) {
    int32_t counter{};
    std::string word;
    char symbol{};
    for (size_t i{}; i < string.size(); ++i) {
       
        symbol = string[i];

        if (isalpha(symbol)) {
            word.push_back(symbol);
        }
        else {
            if (!word.empty() && counter < maxSize) {
                words[counter] = word;
                ++counter;
                word.clear();
            }
        }
    }

    if (!word.empty() && counter < maxSize) {
        words[counter++] = word;
    }

    return counter;
}

void BubbleSort(std::string words[], int size) {
    for (size_t i{}; i < size - 1; i++) {
        for (size_t j{}; j < size - i - 1; j++) {
            if (ToLowerCase(words[j]) > ToLowerCase(words[j + 1]))
            {
                swap(words[j], words[j + 1]);
            }
            else
            {
                break;
            }
        }
    }
}

bool IsEmpty(const std::string& string)
{
    return string.length() == 0;
}

bool OnlyDelimeters(const std::string& string)
{
    bool check = 1;
    for (size_t i{}; i < string.size(); ++i) {
        if (isalpha(string[i])) {
            check = 0;
        }
    }
    return check;
}

int main()
{
    const int32_t maxLenght = 1000;
    std::string firstString;
    std::string secondString;

    std::cout << "Input 1st string: \n";
    std::getline(std::cin, firstString);
    std::cout << "Input 2nd string: \n";
    std::getline(std::cin, secondString);
    std::cout << "\n\n";

    std::string firstWordsArray[maxLenght];
    std::string secondWordsAdress[maxLenght];
    std::string allWords[maxLenght * 2];

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
        int32_t firstCounter = GetWords(firstString, firstWordsArray, maxLenght);
        int32_t secondCounter = GetWords(secondString, secondWordsAdress, maxLenght);

        int32_t totalCounter{};

        for (size_t i{}; i < firstCounter; ++i) {
            allWords[totalCounter] = firstWordsArray[i];
            ++totalCounter;
        }
        for (size_t i{}; i < secondCounter; ++i) {
            allWords[totalCounter] = secondWordsAdress[i];
            ++totalCounter;
        }

        BubbleSort(allWords, totalCounter);

        for (size_t i{}; i < totalCounter; ++i) {
            if (i > 0)
            {
                std::cout << " ";
            }
            std::cout << allWords[i];
        }

        std::cout << '\n';
       
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}