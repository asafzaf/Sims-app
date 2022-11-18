#include "person.h"

Person::Person() {
	m_needs = Needs();
	m_job = Job();
	m_firstName = nullptr;
	m_lastName = nullptr;
	m_money = 0;
	m_ID = 0;
}

Person::Person(int id, char* firstname, char* lastname) {
	m_ID = id;
	m_firstName = firstname;
	m_lastName = lastname;
	m_needs = Needs();
	m_job = Job();
	m_money = 500;
}

Person::~Person() {
	delete m_firstName;
	delete m_lastName;
}