#include "needs.h"
#include "person.h"

Needs::Needs() : m_bladder(), m_social(), m_energy(), m_hunger(), m_fun(), m_hygiene() 
{};

Bladder::Bladder() {m_level = 5;}

Social::Social() {m_level = 5;}
	
Energy::Energy() {m_level = 5;}

Hunger::Hunger() {m_level = 5;}

Fun::Fun() {m_level = 5;}

Hygiene::Hygiene() {m_level = 5;}

void Bladder::UseToilet() {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Social::Talk(Person& person) {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Social::Text(Person& person) {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Social::PhoneCall(Person& person) {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Energy::Sleep() {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Hunger::Eat(Food& food) {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Fun::Dance() {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Fun::PlayGuitar() {
	setLevel(getLevel() + 7);
	if (getLevel() > 10)
		setLevel(10);
}

void Fun::PlayComputer() {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}

void Fun::PetAnimal(Animal& animal) {
	m_level = 10;
	// איך אני מחבר את החיה לאיש??
}

void Hygiene::Shower() {
	setLevel(getLevel() + 5);
	if (getLevel() > 10)
		setLevel(10);
}