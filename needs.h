#include "food.h"
#include "animal.h"

class Bladder {
private:
	int m_level;
public:
	Bladder();
	void UseToilet();
};

class Social {
private:
	int m_level;
public:
	Social();
	void Talk(Person& person);
	void Text(Person& preson);
	void PhoneCall(Person& person);
};

class Energy {
private:
	int m_level;
public:
	Energy();
	void Sleep();
};

class Hunger {
private:
	int m_level;
public:
	Hunger();
	void Eat(Food& food);
};

class Fun {
private:
	int m_level;
public:
	Fun();
	void Dance();
	void PlayGuitar();
	void PlayComputer();
	void PetAnimal(Animal& animal);
};

class Hygiene {
private:
	int m_level;
public:
	Hygiene();
	void Shower();
};

class Needs {
private:
	Bladder m_bladder;
	Social m_social;
	Energy m_energy;
	Hunger m_hunger;
	Fun m_fun;
	Hygiene m_hygiene;
public:
	Needs();
};