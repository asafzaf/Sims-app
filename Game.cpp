#include <iomanip>
#include "game.h"

Game::Game() { // Creating new game (Stack of persons = family).
	std::cout << "Hello there!" << std::endl
		<< "Please choose family name: " << std::endl
		<< "> ";
	char* name = new char[20];
	std::cin >> name;
	m_familyname = name;
	std::cout << std::endl << "Welcome to the " << m_familyname << " family!"
		<< std::endl << "-------------------------" << std::endl;


	m_IDcounter = 100;
	m_number_of_persons = 0;
	m_max_of_family = 10;

	m_person = new Person * [10];
	if (m_person == NULL) { // check pointer.
		std::cout << "Failed to create family!" << std::endl;
		return;
	}

	for (int i = 0; i < m_max_of_family; i++) 
	m_person[i] = nullptr;
}

void Game::addPerson() { // Creating new peron to the game.
	if (m_number_of_persons == m_max_of_family) { // Check if the family is full (10 persons)
		std::cout << std::endl << "Max family members... please delete sombody before you create new one..." << std::endl;
		return;
	}
	// After checking - the family is under 10 members.
	char* first = new char[20];
	char* last = new char[20]; 
	std::cout << std::endl << "Creating new person page:" << std::endl
		<< "------------------------------" << std::endl
		<< "Please complete the information:" << std::endl
		<< "- first Name: ";
	std::cin >> first;

	std::cout << "- Last Name: ";
	std::cin >> last;

	m_IDcounter++; // Giving new ID (increment).

	m_person[m_number_of_persons] = new Person(m_IDcounter, first, last);// Creating new array with the new size of persons.;

	std::cout << "You created new person!" << std::endl // Succesfull
		<< "Your new person: " <<    m_person[m_number_of_persons]->getFirstName() << " " << m_person[m_number_of_persons]->getLastName() << " ID #" << m_person[m_number_of_persons]->getID() << std::endl;

	m_number_of_persons++;  // Updating the new number of persons.

	return;
}

void Game::deletePerson() { // Choose and delete one of the persons in family.
	int choosen_num = choosePerson();
	if (choosen_num == 99)
		return;
	
	Person** ptr = m_person;
	
	if ((choosen_num + 1 > m_number_of_persons) || (choosen_num < 0)) { // Check if there is a person in the slot.
		std::cout << std::endl << "Invalid No. of person!" << std::endl;
		return;
	}

	delete ptr[choosen_num]; // Deleting from memory.
	for (int i = choosen_num; i < m_number_of_persons; i++) // Sorting to the "left".
		ptr[i] = ptr[i + 1];

	m_number_of_persons--;

	std::cout << std::endl << "Sucessfully deleted!" << std::endl << std::endl;
	return;
}

void Game::doSomething(Food** food) { // A routin of do something...
	if (m_number_of_persons == 0) { // Checking if there are persons.
		std::cout << std::endl << "There are no persons!" << std::endl;
		return;
	}
	Person** ptr = m_person;
	
	std::cout << "Let's do something!" << std::endl << "--------------------" << std::endl;

	for (int i = 0; i < m_number_of_persons; i++) {
		Needs temp_need = ptr[i]->getNeeds(); // Pulling needs from person to temp.
		std::cout << "No. | ID  |  name	|Bladder lvl |Social lvl |Energy lvl |Hunger lvl |Fun lvl |Hygiene lvl " << std::endl;
		std::cout << (i + 1) << std::setw(5) << "| "
			<< ptr[i]->getID() << std::setw(2) << "|"
			<< ptr[i]->getFirstName() << " "
			<< ptr[i]->getLastName() << std::setw(5) << "|  "
			<< temp_need.getBladder().getLevel() << std::setw(12) << "|  "
			<< temp_need.getSocial().getLevel() << std::setw(11) << "|  "
			<< temp_need.getEnergy().getLevel() << std::setw(11) << "|  "
			<< temp_need.getHunger().getLevel() << std::setw(11) << "|  "
			<< temp_need.getFun().getLevel() << std::setw(6) << "|"
			<< temp_need.getHygiene().getLevel() << std::endl << std::endl;

		std::cout << "What do you want your person to do?" << std::endl
			<< "1- go to toilet" << std::endl
			<< "2- some social stuff" << std::endl
			<< "3- go to sleep" << std::endl
			<< "4- eat something" << std::endl
			<< "5- have some fun" << std::endl
			<< "6- take a shower" << std::endl
			<< "> ";
		int WhatToDo = 99;
		int WhatToDo_Social = 0;
		int WhatToPlay = 0;
		int WithWho = 99;
		while(WhatToDo > 6 || WhatToDo < 1){ // What to do menu.
			std::cin >> WhatToDo;

			switch (WhatToDo)
			{
			case 1:
				temp_need.useToilet();
				break;
			case 2:
				while (WhatToDo_Social > 3 || WhatToDo_Social < 1) // What to do "social" menu.
				{
					std::cout << "What kind of social active do you like to do?" << std::endl
						<< "1- Talk" << std::endl
						<< "2- Text" << std::endl
						<< "3- PhoneCall" << std::endl
						<< "> ";
					std::cin >> WhatToDo_Social;
					WithWho = choosePerson();
					switch (WhatToDo_Social)
					{
					case 1:
						temp_need.Talk(ptr[WithWho]);
						break;
					case 2:
						temp_need.Text(ptr[WithWho]);
						break;
					case 3:
						temp_need.PhoneCall(ptr[WithWho]);
						break;
					default:
						std::cout << "please enter a number from the menu" << std::endl << "> ";
						break;
					}
				}
				break;
			case 3:
				temp_need.Sleep();
				break;
			case 4:
				temp_need.Eat(food);
				break;
			case 5:
				while (WhatToPlay > 4 || WhatToPlay < 1) // what to do "fun" menu.
				{
					std::cout << "1- Dance" << std::endl
						<< "2- Play Guitar" << std::endl
						<< "3- Play Computer" << std::endl
						<< "4- Pet Animal" << std::endl
					<< "> ";
					std::cin >> WhatToPlay;
					switch (WhatToPlay)
					{
					case 1:
						temp_need.Dance();
						break;
					case 2:
						temp_need.PlayGuitar();
						break;
					case 3:
						temp_need.PlayComputer();
						break;
					case 4:
						temp_need.PetAnimal();
						break;
					default:
						std::cout << "please enter a number from the menu" << std::endl << "> ";
						break;
					}
				}
				break;
			case 6:
				temp_need.Shower();
			default:
				std::cout << "please enter a number from the menu" << std::endl << "> ";
				break;
			}
		}
		temp_need.DropOne(); // Droping on to all parameters.
		ptr[i]->setNeeds(temp_need); // Pushing back the new values the person.
	}
	PrintWarnings(); // Print Warning for all of the "parameter < 3" values.
	return;
}

int Game::choosePerson() { // Choosing function for persons
	if (m_number_of_persons == 0) { // Checing if there are persons.
		std::cout << std::endl << "There are no persons!" << std::endl;
		return 99;
	}
	Person** ptr = m_person;
	int choose;
	std::cout << std::endl << "Please choose a person (by No.):" << std::endl;
	std::cout << "No.  | ID	|  name			|  money " << std::endl;
	for (int i = 0; i < m_number_of_persons; i++) {
		std::cout << (i+1) << "    | " << ptr[i]->getID() << "	| " << ptr[i]->getFirstName() << " " << ptr[i]->getLastName() << "		| " << ptr[i]->getMoney() << std::endl;
	}
	std::cout << std::endl << "Type No. : ";
	std::cin >> choose;
	choose -= 1;
	std::cout << std::endl;
	return choose;
}

Game::~Game() {
	delete[] m_person;
	delete m_familyname;
}

void Game::PrintWarnings() {
	Person** person_ptr = m_person;
	for (int j = 0; j < m_number_of_persons; j++) {
		Needs warningsNeeds = person_ptr[j]->getNeeds();
		int bladderlvl = warningsNeeds.getBladder().getLevel();
		int sociallvl = warningsNeeds.getSocial().getLevel();
		int energylvl = warningsNeeds.getEnergy().getLevel();
		int hungerlvl = warningsNeeds.getHunger().getLevel();
		int funlvl = warningsNeeds.getFun().getLevel();
		int hygienelvl = warningsNeeds.getHygiene().getLevel();
		if (bladderlvl < 4)
			std::cout << "Warning! " << person_ptr[j]->getFirstName() << " " << person_ptr[j]->getLastName() << " bladder level is low! (" << bladderlvl << ")" << std::endl;
		if (sociallvl < 4)
			std::cout << "Warning! " << person_ptr[j]->getFirstName() << " " << person_ptr[j]->getLastName() << " social level is low! (" << sociallvl << ")" << std::endl;
		if (energylvl < 4)
			std::cout << "Warning! " << person_ptr[j]->getFirstName() << " " << person_ptr[j]->getLastName() << " energy level is low! (" << energylvl << ")" << std::endl;
		if (hungerlvl < 4)
			std::cout << "Warning! " << person_ptr[j]->getFirstName() << " " << person_ptr[j]->getLastName() << " hunger level is low! (" << hungerlvl << ")" << std::endl;
		if (funlvl < 4)
			std::cout << "Warning! " << person_ptr[j]->getFirstName() << " " << person_ptr[j]->getLastName() << " fun level is low! (" << funlvl << ")" << std::endl;
		if (hygienelvl < 4)
			std::cout << "Warning! " << person_ptr[j]->getFirstName() << " " << person_ptr[j]->getLastName() << " social level is low! (" << hygienelvl << ")" << std::endl;
	}
}