#include "game.h"

Game::Game() {
	m_IDcounter = 100;
	m_number_of_persons = 0;
	m_max_of_family = 0;
}

void Game::startGame() {
	char* fam_name;
	std::cout << "Hello there!" << std::endl
		<< "Please choose family name:	" << std::endl;

	std::cin >> fam_name;
	setFamilyName(fam_name);

	std::cout << std::endl << "Welcome to the " << fam_name << "!" << std::endl;
}

void Game::addPerson() {
	if (m_number_of_persons == m_max_of_family) { // Check if the family is full (10 persons)
		std::cout << std::endl << "Max family members... please delete sombody to create new" << std::endl;
		return;
	}

	char *first, *last; // After checking - the family is under 10 members.
		std::cout << std::endl << "Creating new person page:" << std::endl
		<< "-------------------------" << std::endl
		<< "Please complete the information:" << std::endl
		<< "- first Name: ";
	std::cin >> first;
	std::cout << std::endl << "- Last Name: ";
	std::cin >> last;

	++m_number_of_persons;  // Updating the new number of persons.

	Person* person_array = new Person[m_number_of_persons];  // Creating new array with the new size of persons.
	if (person_array == NULL) { // check pointer.
		std::cout << "Failed to create new person!" << std::endl;
		return;
	}	

	for (int i = 0; i < m_number_of_persons; i++) { // Copy the data.
		memccpy(person_array, m_person, m_number_of_persons, sizeof(m_person));
	}

	person_array[m_number_of_persons] = Person(++m_IDcounter, first, last); // Add new data.

	std::cout << "You created new person!" << std::endl // Succesful!
		<< "Your new person: " << person_array[m_number_of_persons].getFirstName() << " " << person_array[number_of_persons].getLastName() << " ID #" << person_array[number_of_persons].getID() << std::endl;

	delete[] m_person; // Clear old data from memory.
	
	m_person = person_array; // Updating the new pointer of the game for the new one.

	return;
}

void deletePerson() { // Choose and delete one of the persons.
	
}

void doSomething() { // A routin

}

int choosePerson() {

}