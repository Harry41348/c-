// Files.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
    /*std::ofstream file;
    file.open("hello.txt");*/

    /*std::string filename;
    std::cout << "Which file would you like to write to? ";
    std::cin >> filename;*/

    // std::ofstream file("hello.txt", std::ios::app);  // Appends to file
    // std::ofstream file("names.txt"); // Overwrites file

    /*if (file.is_open())
    {
        std::cout << "Succesfully opened\n";
    }

    std::vector<std::string> names;
    names.push_back("Harry");
    names.push_back("Rachel");

    for (std::string name : names)
    {
        file << name << std::endl;
    }


    file.close();*/


    std::ifstream file("names.txt");

    /*std::vector<std::string> names;

    std::string input;
    while (file >> input)
    {
        names.push_back(input);
    }

    for (std::string name : names)
    {
        std::cout << name << std::endl;
    }*/

    std::string line;

    getline(file, line);

    std::cout << line << "\n";

    std::vector<std::string> names;

    while (getline(file, line))
    {
        names.push_back(line);
    }

    for (std::string name : names)
    {
        std::cout << name << std::endl;
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
