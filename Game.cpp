#include "game.h"

Game::Game() {
	std::cout << "Hello there!" << std::endl
		<< "Please choose family name: " << std::endl
		<< "> ";
	char* name = new char[20];
	std::cin >> name;
	m_familyname = name;
	std::cout << std::endl << "Welcome to the " << m_familyname << " family!" 
		<< std::endl << "-------------------------" << std::endl;

	m_person = new Person*[10];
	if (m_person == NULL) { // check pointer.
		std::cout << "Failed to create family!" << std::endl;
		return;
	}
	for (int i = 0; i < m_max_of_family; i++)
		m_person[i] = nullptr;
	m_IDcounter = 100;
	m_number_of_persons = 0;
	m_max_of_family = 10;
}

void Game::addPerson() {
	if (m_number_of_persons == m_max_of_family) { // Check if the family is full (10 persons)
		std::cout << std::endl << "Max family members... please delete sombody before you create new one..." << std::endl;
		return;
	}
	
	char* first = new char[20];
	char* last = new char[20]; // After checking - the family is under 10 members.
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

void Game::deletePerson() { // Choose and delete one of the persons.
	int choosen_num = choosePerson();
	if (choosen_num == 99)
		return;
	
	Person** ptr = m_person;
	
	if ((choosen_num + 1 > m_number_of_persons) || (choosen_num < 0)) { // Check if there is a person in the slot.
		std::cout << std::endl << "Invalid No. of person!" << std::endl;
		return;
	}

	delete ptr[choosen_num];
	for (int i = choosen_num; i < m_number_of_persons; i++)
		ptr[i] = ptr[i + 1];

	m_number_of_persons--;

	std::cout << std::endl << "Sucessfully deleted!" << std::endl;
	return;
}

void Game::doSomething() { // A routin of do something...
	if (m_number_of_persons == 0) {
		std::cout << std::endl << "There are no persons!" << std::endl;
		return;
	}
	Person** ptr = m_person;
	
	std::cout << "Let's do something!" << std::endl << "--------------------" << std::endl;

	for (int i = 0; i < m_number_of_persons; i++) {
		std::cout << "No. | ID  |  name       | Bladder lvl | Social lvl | Energy lvl | Hunger lvl | Fun lvl | Hygiene lvl " << std::endl;
		std::cout << (i + 1) << " | " 
			<< ptr[i]->getID() << "|" 
			<< ptr[i]->getFirstName() << " | " 
			<< ptr[i]->getLastName() << " | " 
			<< ptr[i]->getNeeds().getBladder().getLevel() << " | "
			<< ptr[i]->getNeeds().getSocial().getLevel() << " | "
			<< ptr[i]->getNeeds().getEnergy().getLevel() << " | "
			<< ptr[i]->getNeeds().getHunger().getLevel() << " | "
			<< ptr[i]->getNeeds().getFun().getLevel() << " | "
			<< ptr[i]->getNeeds().getHygiene().getLevel() << std::endl;
		std::cout << "What do you want your person to do?" << std::endl
			<< "1- go to toilet" << std::endl
			<< "2- eat" << std::endl
			<< "3- talk" << std::endl // there are options
			<< "4- have fun" << std::endl
			<< "5- sleep" << std::endl
			<< "6- take a shower" << std::endl
			<< "> ";
		int WhatToDo = 99;
		int WhatToDo_Social = 0;
		int WhatToEat = 0;
		int WhatToPlay = 0;
		int WithWho = 99;
		std::cin >> WhatToDo;
		switch (WhatToDo)
		{
		case 1:
			ptr[i]->getNeeds().getBladder().UseToilet();
			break;
		case 2:
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
				ptr[i]->getNeeds().getSocial().Talk(ptr[WithWho]);
				break;
			case 2:
				ptr[i]->getNeeds().getSocial().Text(ptr[WithWho]);
				break;
			case 3:
				ptr[i]->getNeeds().getSocial().PhoneCall(ptr[WithWho]);
				break;
			default:
				std::cout << "please enter a number from the menu" << std::endl;
				break;	
			}
			break;
		case 3:
			ptr[i]->getNeeds().getEnergy().Sleep();
			break;
		case 4:
			std::cin >> WhatToEat;
			//ptr[i]->getNeeds().getHunger().Eat();
			break;
		case 5:
			std::cout << "1- Dance" << std::endl
				<< "2- Play Guitar" << std::endl
				<< "3- Play Computer" << std::endl
				<< "> ";
			std::cin >> WhatToPlay;
			switch (WhatToPlay)
			{
			case 1:
				ptr[i]->getNeeds().getFun().Dance();
				break;
			case 2:
				ptr[i]->getNeeds().getFun().PlayGuitar();
				break;
			case 3:
				ptr[i]->getNeeds().getFun().PlayComputer();
				break;
			case 4:
				//ptr[i]->getNeeds().getFun().PetAnimal();
				break;
			default:
				break;
			}
			break;
		case 6:
			ptr[i]->getNeeds().getHygiene().Shower();
		default:
			std::cout << "please enter a number from the menu" << std::endl;
			break;
		}
		for (int j = 0; j < m_number_of_persons; j++) // decrease all stats in one.
		{
			int bladderLvl = ptr[j]->getNeeds().getBladder().getLevel();
			int socialLvl = ptr[j]->getNeeds().getSocial().getLevel();
			int energyLvl = ptr[j]->getNeeds().getEnergy().getLevel();
			int hungerLvl = ptr[j]->getNeeds().getHunger().getLevel();
			int funLvl = ptr[j]->getNeeds().getFun().getLevel();
			int hygieneLvl = ptr[j]->getNeeds().getHygiene().getLevel();

			ptr[j]->getNeeds().getBladder().setLevel((bladderLvl - 1));
			ptr[j]->getNeeds().getSocial().setLevel((socialLvl - 1));
			ptr[j]->getNeeds().getEnergy().setLevel((energyLvl - 1));
			ptr[j]->getNeeds().getHunger().setLevel((hungerLvl - 1));
			ptr[j]->getNeeds().getFun().setLevel((funLvl - 1));
			ptr[j]->getNeeds().getHygiene().setLevel((hungerLvl - 1));
		}
	}
	return;
}

int Game::choosePerson() { // Choosing function for persons
	if (m_number_of_persons == 0) {
		std::cout << std::endl << "There are no persons!" << std::endl;
		return 99;
	}
	Person** ptr = m_person;
	int choose;
	std::cout << std::endl << "Please choose a person (by No.):" << std::endl;
	std::cout << "No. | ID  |  name       |   money " << std::endl;
	for (int i = 0; i < m_number_of_persons; i++) {
		std::cout << (i+1) << " | " << ptr[i]->getID() << "|" << ptr[i]->getFirstName() << " | " << ptr[i]->getLastName() << " | " << ptr[i]->getMoney() << std::endl;
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