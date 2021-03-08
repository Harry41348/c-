// MadLibs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string colour, pluralNoun, celebrity;

    std::cout << "Enter a colour: ";
    std::getline(std::cin, colour);

    std::cout << "Enter a plural noun: ";
    std::getline(std::cin, pluralNoun);

    std::cout << "Enter a celebrity: ";
    std::getline(std::cin, celebrity);

    std::cout << "Roses are " << colour << std::endl;
    std::cout << pluralNoun << " are blue" << std::endl;
    std::cout << "I love " << celebrity << std::endl;
}