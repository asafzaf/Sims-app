#pragma once

class Person;
class Food;
class Animal;

class Bladder {
private:
	int m_level;
public:
	Bladder();
	int getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
	void UseToilet();
};

class Social {
private:
	int m_level;
public:
	Social();
	int getLevel() { return m_level; }
	void setLevel(int level) { m_level = level;}
	void Talk(Person* person);
	void Text(Person* preson);
	void PhoneCall(Person* person);
};

class Energy {
private:
	int m_level;
public:
	Energy();
	int getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
	void Sleep();
};

class Hunger {
private:
	int m_level;
public:
	Hunger();
	int getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
	void Eat(Food& food);
};

class Fun {
private:
	int m_level;
public:
	Fun();
	int getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
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
	int getLevel() { return m_level; }
	void setLevel(int level) { m_level = level; }
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
	
	Bladder getBladder() { return m_bladder; }
	void setBladder(Bladder bladder) { m_bladder = bladder; }

	Social getSocial() { return m_social; }
	void setSocial(Social social) { m_social = social; }

	Energy getEnergy() { return m_energy; }
	void setEnergy(Energy energy) { m_energy = energy; }

	Hunger getHunger() { return m_hunger; }
	void setHunger(Hunger hunger) { m_hunger = hunger; }

	Fun getFun() { return m_fun; }
	void setFun(Fun fun) { m_fun = fun; }

	Hygiene getHygiene() { return m_hygiene; }
	void setHygiene(Hygiene hygiene) { m_hygiene = hygiene; }
};