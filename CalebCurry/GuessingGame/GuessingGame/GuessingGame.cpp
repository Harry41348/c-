// GuessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void save_score(int guess_count)
{
    std::ifstream input("high_score.txt");

    int best_score;
    input >> best_score;

    std::ofstream output("high_score.txt");
    if (guess_count < best_score)
    {
        output << guess_count;
        std::cout << "New high score! New score: " << guess_count << std::endl;
    }
    else {
        output << best_score;
        std::cout << "High score is still: " << best_score << std::endl;
    }

    output.close();
}

void print_stats(std::vector<int> guesses) {
    std::cout << "Guesses: " << guesses.size() << "\nYour guesses were: ";

    for (int g : guesses) {
        std::cout << g << "  ";
    }

    std::cout << "\n";
}

void play_game() {
    std::vector<int> guesses;
    int random = rand() % 251;
    std::cout << "Keep guessing until you get it right! Range: 0-250\n";

    while (true) {
        int guess;
        std::cin >> guess;
        guesses.push_back(guess);
        if (guess == random) {
            std::cout << "You won!\n";
            break;
        }
        else if (guess < random) {
            std::cout << "Guess is too low!\n";
        }
        else {
            std::cout << "Guess is too high!\n";
        }
    }

    save_score(guesses.size());

    print_stats(guesses);
}

int main()
{
    srand(time(NULL));
    int choice;
    do {
        std::cout << "0. Quit\n1. Play Game\n";
        std::cin >> choice;
        switch (choice) {
            case 0:
                std::cout << "Goodbye!\n";
                break;
            case 1:
                play_game();
                break;
            default:
                std::cout << "Option must be either 1 or 0!\n";
        }
    } while (choice != 0);
    
}