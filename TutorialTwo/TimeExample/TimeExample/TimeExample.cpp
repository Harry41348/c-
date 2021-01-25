// TimeExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Time.h"
#include<Windows.h>

using namespace std;

int main()
{
	Time t;	//new time object
	cout << "\nThe initial time is ";
	t.printTime();
	t.setTime(13, 25, 12); //set the time
	cout << "\nThe set time is ";
	t.printTime();
	for (int i = 0; i < 10; i++) {
		cout << "\n";
		t.tckTime();
		t.printTime();
		Sleep(1000);
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
