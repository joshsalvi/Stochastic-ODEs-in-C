#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned int generateRandomNumberInRange(unsigned int lowEnd, unsigned int highEnd)
{
    if(highEnd < lowEnd)
    {
        unsigned int tempForSwap = highEnd;
        highEnd = lowEnd;
        lowEnd = tempForSwap;
    }

    int rangeVal = (highEnd - lowEnd) + 1;
    return (std::rand() % rangeVal) + lowEnd;
}

int main()
{
    std::srand(std::time(nullptr));

    unsigned int randBetweenOneAndFifty = generateRandomNumberInRange(1, 50);
    std::cout << randBetweenOneAndFifty << std::endl;

    unsigned int randBetweenOneAndFifteen = generateRandomNumberInRange(1, 15);
    std::cout << randBetweenOneAndFifteen << std::endl;

    return 0;