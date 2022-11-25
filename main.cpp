#include "Game.h"
#include "food.h"

using namespace std;
Food** Foodlist();


int main() {
	int choice = 99;
	Game family = Game();
	Food** foodlist = Foodlist();

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
			family.doSomething(foodlist);
			break;
		case 0:
			return 0;
		}
	}
}


Food** Foodlist() {
	Food** list = new Food*[5];
	Food** ptr = list;
	
	ptr[0] = new Food("Onion Soup", 5, 1);
	ptr[1] = new Food("Pancake", 5, 1);
	ptr[2] = new Food("Apple", 5, 0);
	ptr[3] = new Food("Schnizel", 5, 1);
	ptr[4] = new Food("nuts", 5, 0);

	return list;
}