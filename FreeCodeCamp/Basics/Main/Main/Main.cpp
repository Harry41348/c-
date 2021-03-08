
#include <iostream>
#include <string>
#include "draw.h";

int main()
{
    std::string name = "Harry";
    std::string shape = "squares";
    std::cout << name << " likes " << shape << ".\n";
    drawSquare();

    std::string word = "Hello world!";
    std::cout << std::endl << word[0] << std::endl; // Select a specific character in the string
    std::cout << word.find("lo", 2) << std::endl; // Find a set of characters in a string, returns the start of the set of characters
    std::cout << word.substr(6, 5) << std::endl; // Get a substring of the string

    int age;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "You are " << age << " years old, and your name is " << name << std::endl;

    int luckyNums[] = {4, 8, 16, 32, 64};
    int luckyNums[10];

    std::cout << luckyNums[3];

    return 0;
}