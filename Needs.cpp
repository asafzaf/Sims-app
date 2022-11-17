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
	m_level += 5;
}

void Social::Talk(Person& person) {
	m_level += 5;
}

void Social::Text(Person& person) {
	m_level += 5;
}

void Social::PhoneCall(Person& person) {
	m_level += 5;
}

void Energy::Sleep() {
	m_level += 5;
}

void Hunger::Eat(Food& food) {
	m_level += food.getWorth();
}

void Fun::Dance() {
	m_level += 5;
}

void Fun::PlayGuitar() {
	m_level += 7;
}

void Fun::PlayComputer() {
	m_level += 5;
}

void Fun::PetAnimal(Animal& animal) {
	m_level = 10;
	// איך אני מחבר את החיה לאיש??
}

void Hygiene::Shower() {
	m_level += 5;
}