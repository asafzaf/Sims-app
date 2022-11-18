#include "game.h"

Game::Game() {
	std::cout << "Hello there!" << std::endl
		<< "Please choose family name: " << std::endl
		<< "> ";
	char* name = new char[20];
	std::cin >> name;
	m_familyname = name;
	std::cout << std::endl << "Welcome to the " << m_familyname << " family!" << std::endl << "-------------------------" << std::endl;
	m_person = nullptr;
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


	Person* person_array = new Person[m_number_of_persons+1];// Creating new array with the new size of persons.
	if (person_array == NULL) { // check pointer.
		std::cout << "Failed to create new person!" << std::endl;
		return;
	}	
	if ( m_number_of_persons != 0 )
		memcpy(person_array, m_person, m_number_of_persons * sizeof(m_person));

	m_number_of_persons++;  // Updating the new number of persons.
	m_IDcounter++; // Giving new ID (increment).

	person_array[m_number_of_persons-1] = Person(m_IDcounter, first, last); // Add new data.

	std::cout << "You created new person!" << std::endl // Succesfull
		<< "Your new person: " << person_array[m_number_of_persons-1].getFirstName() << " " << person_array[m_number_of_persons-1].getLastName() << " ID #" << person_array[m_number_of_persons-1].getID() << std::endl;

	m_person = person_array; // Updating the new pointer of the game for the new one.

	return;
}

void Game::deletePerson() { // Choose and delete one of the persons.
	int choose_num = choosePerson();
	Person* ptr = m_person;
	if (choose_num == 0) {
		m_number_of_persons--;
		Person* person_array = new Person[m_number_of_persons];
		if (person_array == NULL) { // check pointer.
			std::cout << "Failed to create new list!" << std::endl;
			m_number_of_persons++;
			return;
		}
		ptr++;

		memcpy(person_array, ptr, m_number_of_persons * sizeof(m_person));

		m_person = ptr;
		return;
	}
	else if ( (choose_num + 1 > m_number_of_persons) || (choose_num < 0) ) {
		std::cout << std::endl << "Invalid No. of person!" << std::endl;
		return;
	}
	else {
		for (int i = choose_num; i < (m_number_of_persons - 1) ; i++) {
			ptr[choose_num] = ptr[choose_num + 1];
		}
		m_number_of_persons--;

		Person* person_array = new Person[m_number_of_persons];
		if (person_array == NULL) { // check pointer.
			std::cout << "Failed to create new list!" << std::endl;
			m_number_of_persons++;
			return;
		}

		memcpy(person_array, m_person, m_number_of_persons * sizeof(m_person));

		m_person = person_array;

		std::cout << std::endl << "Sucessfully deleted!" << std::endl;

		return;
	}

}

//void Game::doSomething() { // A routin of do something...
//
//}

int Game::choosePerson() { // Choosing function for persons
	if (m_number_of_persons == 0)
		std::cout << std::endl << "There are no persons!" << std::endl;
	Person* ptr = m_person;
	int choose;
	std::cout << std::endl << "Please choose a person (by No.):" << std::endl;
	std::cout << "No. | ID  |  name       |   money " << std::endl;
	for (int i = 0; i < m_number_of_persons; i++) {
		std::cout << (i+1) << " | " << ptr->getID() << "|" << ptr->getFirstName() << " | " << ptr->getLastName() << " | " << ptr->getMoney() << std::endl;;
	}
	std::cout << std::endl << "Type No. : ";
	std::cin >> choose;
	choose -= 1;
	std::cout << std::endl;
	return choose;
}

Game::~Game() {
	delete m_person;
	delete m_familyname;
}