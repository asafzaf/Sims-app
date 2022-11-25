#include "needs.h"
#include "job.h"

class Person {
private:
	int m_ID;
	const char* m_firstName;
	const char* m_lastName;
	Needs m_needs;
	Job m_job;
	int m_money;
public:

	int getID() { return m_ID; }
	void setID(int id) { m_ID = id; }

	const char* getFirstName() { return m_firstName; }
	void setFirstName(char* firstname) { m_firstName = firstname; }

	const char* getLastName() { return m_lastName; }
	void setLastName(char* lastname) { m_lastName = lastname; }

	int getMoney() { return m_money; }
	void setMooney(int m_money) { m_money = m_money; }

	Needs getNeeds() { return m_needs; }
	void setNeeds(Needs needs) { m_needs = needs; }

	Job getJob() { return m_job; }
	void SetJob(Job job) { m_job = job; }

	Person();
	Person(int id, char* firstname, char* lastname);
	~Person();
};
