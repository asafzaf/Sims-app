#include "Game.h"

using namespace std;

int main() {
	int choice = 99;
	Game family = Game();

	while (choice != 0) {
		cout << "Please choose an option:" << endl
			<< "-------------------------" << endl
			<< "1 - Create new person." << endl
			<< "2 - Delete some person." << endl
			<< "3 - Do something:" << endl
			<< "0 - Exit..." << endl
			<< "-------------------------" << endl
			<< "> ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			family.addPerson();
			break;
		case 2:
			family.deletePerson();
			break;
		case 3:
			family.doSomething();
			break;
		case 0:
			return 0;
		}
	}
}


