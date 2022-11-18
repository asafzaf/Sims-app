#include <iostream>
#include "person.h"

class Game {
private:
	Person* m_person;
	char* m_familyname;
	int m_IDcounter;
	int m_number_of_persons;
	int m_max_of_family;
public:
	Game();
	~Game();

	char* getFamilyName() { return m_familyname; }
	void setFamilyName(char* FamilyName) { m_familyname = FamilyName; }

	int getIDcounter() { return m_IDcounter; }
	void setIDcounter(int idcounter) { m_IDcounter = idcounter; }

	int getNumberOfPersons() { return m_number_of_persons; }
	void setNumbarOfPersons(int num_of_per) { m_number_of_persons = num_of_per; }

	int getMaxOfFamily() { return m_max_of_family; }

	void addPerson();
	void deletePerson();
	int choosePerson();
	//void doSomething();
};