// TutorialOne.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "math.h"
using namespace std; // Bad practice

void practice() {
    //std::cout << string <- Better practice
    int a, b;
    cout << "Hello Universe\nWhat is your first number? ";
    std::cin >> a;
    cout << "What is your second number? ";
    std::cin >> b;
    cout << "Thanks!\n";
    cout << add(a, b) << "\n";
    cout << multiply(a, b) << "\n";
    cout << divide(a, b) << "\n";
}

void task1() {
    std::vector<int> nums(5);
    int min, max;
    for (int i = 0; i < 5; i++) {
        std::cout << "Number " << i+1 << ": ";
        std::cin >> nums[i];
        if (i == 0) {
            min = nums[i];
            max = nums[i];
        }
        else if (nums[i] < min) { min = nums[i]; }
        else if (nums[i] > max) { max = nums[i]; }
    }
    std::cout << "Min: " << min << "\nMax: " << max;
}

void task2() {
    int num;
    for (int i = 0; i < 10; i++) {
        std::cout << "Number " << i + 1 << ": ";
        std::cin >> num;
        std::cout << "Squared result: " << num * num << "\n";
    }
}

void task3() {
    int checkout = 0,num = 0;
    while (num != -1) {
        checkout += num;
        std::cout << "What number do you want to add to the total? (type -1 to stop) ";
        std::cin >> num;
    }
    std::cout << "Total: " << checkout;
}

int main()
{
    int program;
    std::cout << "Which program to run? ";
    std::cin >> program;
    switch (program) {
    case 1: 
        practice();
        break;
    case 2:
        task1();
        break;
    case 3:
        task2();
        break;
    case 4:
        task3();
        break;
    default:
        std::cout << "Must be a number from the following: 1, 2";
    }

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
