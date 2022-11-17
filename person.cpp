#include "person.h"

Person::Person(int id, char* firsname, char* lastname) {
	m_ID = id;
	m_firstName = firsname;
	m_lastName - lastname;
	Needs();
	Job();
	m_money = 500;
}

int searchForFreeID(Person& family) {

}

bool IDexist(const Person& family) {

}

Person::~Person() {
	delete m_firstName;
	delete m_lastName;
}