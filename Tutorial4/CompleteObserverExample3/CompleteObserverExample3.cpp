// CompleteObserverExample3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Observer.h"
#include "Subject.h"
//#include "ClientCode.cpp"

int main() {
	Subject* subject = new Subject("");
	Observer* observer1 = new Observer(subject);
	Observer* observer2 = new Observer(subject);
	Observer* observer3 = new Observer(subject);
	Observer* observer4;
	Observer* observer5;

	subject->CreateMessage("Hello World! :D");
	observer3->RemoveMeFromTheList();

	subject->CreateMessage("The weather is hot today! :p");
	observer4 = new Observer(subject);

	observer2->RemoveMeFromTheList();
	observer5 = new Observer(subject);

	subject->CreateMessage("My new car is great! ;)");
	observer5->RemoveMeFromTheList();

	observer4->RemoveMeFromTheList();
	observer1->RemoveMeFromTheList();

	delete observer5;
	delete observer4;
	delete observer3;
	delete observer2;
	delete observer1;
	delete subject;
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
