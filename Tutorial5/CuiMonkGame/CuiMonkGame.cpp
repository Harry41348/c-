
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void printRoom(string fileName) //Prints the text file on screen
{
	fstream file(fileName);		//fstream represents the file stream (both ofstream and ifstream capabilities).

	if (file.is_open()) {
		cout << file.rdbuf();
		file.close();
	}
	else {
		cout << "Error - File cannot be opened";
	}
}

int main()
{
	string fileName = "SplashScreen.txt";
	printRoom(fileName);
}

