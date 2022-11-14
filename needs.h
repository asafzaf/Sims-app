#include <iostream>
#include "food.h"
#include "animal.h"

class Needs {
private:
	Bladder bladder;
	Social social;
	Energy energy;
	Hunger hunger;
	Fun fun;
	Hygiene hygiene;
public:
	Needs();
};

class Bladder {
private:
	int level;
public:
	Bladder();
	void UseToilet();
};

class Social {
private:
	int level;
public:
	Social();
	void Talk(Person person);
	void Text(Person preson);
	void PhoneCall(Person person);
};

class Energy {
private:
	int level;
public:
	Energy();
	void Sleep();
};

class Hunger {
private:
	int level;
public:
	Hunger();
	void Eat(Food food);
};

class Fun {
private:
	int level;
public:
	Fun();
	void Dance();
	void PlayGuitar();
	void PlayComputer();
	void PetAnimal(Animal animal);
};

class Hygiene {
private:
	int level;
public:
	Hygiene();
	void Shower();
};