#include "Game.h"
#include "person.h"

using namespace std;


void addPerson(Person& person);
void deletePerson(Person& person);
void DoSomething(Person person);


int main() {
	const int max_of_family = 10;
	int choise = 99;
	int num_of_person = 0;
	Game family = Game();

	family.startGame();


	while (choise != 0) {
		cout << "Please choose an option:" << endl
			<< "1 - Create new person." << endl
			<< "2 - Delete some person." << endl
			<< "3 - Do something:" << endl
			<< "0 - Exit..." << endl;

		switch (choise)
		{
		case 1:
			family.addPerson();
			break;
		case 2:

			break;
		case 3:

			DoSomething()
			break;
		case 0:
			return 0;
		}
	}
}



void DoSomething(Person person) {
	int WhatToDo = 0;
	
	
	
}

