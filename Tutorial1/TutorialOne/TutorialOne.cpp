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
    std::cout << "Total: " << checkout << std::endl;
}

void task4() {
    int a, b;
    char op;
    std::cout << "Number 1: ";
    std::cin >> a;
    std::cout << "Operator: ";
    std::cin >> op;
    std::cout << "Number 2: ";
    std::cin >> b;
    switch (op) {
    case '+':
        std::cout << "Result: " << a + b;
        break;
    case '-':
        std::cout << "Result: " << a - b;
        break;
    case '/':
        std::cout << "Result: " << a / b;
        break;
    case '*':
        std::cout << "Result: " << a * b;
        break;
    default:
        std::cout << "Operator choices: + - * /";
    }
}

void task5() {
    int size = 0;
    std::cout << "Input bar chart value. Negative number to stop program: ";
    while (size >= 0) {
        std::cin >> size;
        if (size < 0) { break; }
        else if (size < 20) {
            for (int i = 0; i < size; i++) {
                std::cout << '*';
            }
        }
        else {
            std::cout << "Value must be less than 20";
        }
    }
}

void task6(){
    int code, wage, hours, pay, sales;
    std::cout << "Input pay code, choice - 1(Manager), 2(Hourly worker), 3(Commision worker), 4(Pieceworker): ";
    std::cin >> code;
    switch (code) {
    case 1:
        std::cout << "Managers wage: ";
        std::cin >> wage;
        if (wage >= 5000) {
            wage /= 52;
        }
        std::cout << "Weekly wage: " << wage;
        break;
    case 2:
        std::cout << "Workers hourly wage: ";
        std::cin >> wage;
        std::cout << "Hours worked: ";
        std::cin >> hours;
        if (hours <= 40) {
            pay = hours * wage;
        }
        else {
            pay = (wage * 40) + ((wage * 1.5) * (hours - 40));
        }
        std::cout << "Weekly wage: " << pay;
        break;
    case 3:
        std::cout << "Gross weekly sales: ";
        std::cin >> sales;
        pay = 250 + (sales * 0.057);
        std::cout << "Weekly wage: " << pay;
        break;
    case 4:
        int items;
        std::cout << "Items produces: ";
        std::cin >> items;
        std::cout << "Wage: " << items * 1.5;
        break;
    default:
        std::cout << "Error: Code must be 1, 2, 3 or 4";
    }
}

int main()
{
    int input = 0;
    while (input != -1) {
        std::cout << "Which program to run? -1 to exit ";
        std::cin >> input;
        switch (input) {
        case 0:
            practice();
            break;
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        default:
            std::cout << "Must be a number from the following: 0, 1, 2, 3, 4, 5, 6";
        }
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
