#include "needs.h"
#include "job.h"

class Person {
private:
	int m_ID;
	char* m_firstName;
	char* m_lastName;
	Needs m_needs;
	Job m_job;
	int m_money;
public:
	int getID() { return m_ID; }
	void setID(int id) { m_ID = id; }

	char* getFirstName() { return m_firstName; }
	void setFirstName(char* firstname) { m_firstName = firstname; }

	char* getLastName() { return m_lastName; }
	void setLastName(char* lastname) { m_lastName = lastname; }

	int getMoney() { return m_money; }
	void setMooney(int m_money) { m_money = m_money; }

	Person();
	Person(int id, char* firstname, char* lastname);
	~Person();
};
