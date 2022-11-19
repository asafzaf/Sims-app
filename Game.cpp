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
		std::cout << std::endl << "Max family members... please delete sombody to create new" << std::endl;
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

//void Game::doSomething() { // A routin of do something...
//
//}

int Game::choosePerson() { // Choosing function for persons
	if (m_number_of_persons == 0)
		std::cout << std::endl << "There are no persons!" << std::endl;
	Person** ptr = m_person;
	int choose;
	std::cout << std::endl << "Please choose a person (by No.):" << std::endl;
	std::cout << "No. | ID  |  name       |   money " << std::endl;
	for (int i = 0; i < m_number_of_persons; i++) {
		std::cout << (i+1) << " | " << ptr[i]->getID() << "|" << ptr[i]->getFirstName() << " | " << ptr[i]->getLastName() << " | " << ptr[i]->getMoney() << std::endl;;
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