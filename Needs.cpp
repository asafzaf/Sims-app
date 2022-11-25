#include <iostream>
#include "needs.h"
#include "person.h"
#include "animal.h"

Needs::Needs() : m_bladder(), m_social(), m_energy(), m_hunger(), m_fun(), m_hygiene() 
{};

Bladder::Bladder() {m_level = 5;}
Social::Social() {m_level = 5;}
Energy::Energy() {m_level = 5;}
Hunger::Hunger() {m_level = 5;}
Fun::Fun() {m_level = 5;}
Hygiene::Hygiene() {m_level = 5;}


//-------Needs Methods-------//
void Needs::useToilet() {
	int temp = m_bladder.getLevel() + 5;
	if (temp > 10)
		m_bladder.setLevel(10);
	else m_bladder.setLevel(temp);
}

void Needs::Talk(Person* person) {
	int temp = m_social.getLevel() + 5;
	if (temp > 10)
		m_social.setLevel(10);
	else m_social.setLevel(temp);
}

void Needs::Text(Person* person) {
	int temp = m_social.getLevel() + 5;
	if (temp > 10)
		m_social.setLevel(10);
	else m_social.setLevel(temp);
}

void Needs::PhoneCall(Person* person) {
	int temp = m_social.getLevel() + 5;
	if (temp > 10)
		m_social.setLevel(10);
	else m_social.setLevel(temp);
}

void Needs::Sleep() {
	int temp = m_energy.getLevel() + 5;
	if (temp > 10)
		m_energy.setLevel(10);
	else m_energy.setLevel(temp);
}

void Needs::Eat(Food** food) {
	Food** ptr_food = food;
	int choice_food = 0;
	std::cout << "Please choose food:" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << i+1 << " - " << ptr_food[i]->getName() << std::endl;
	}
	std::cout << "> ";
	std::cin >> choice_food;
	while (choice_food > 5 || choice_food < 1) {
		std::cout << "Please choose real food!" << std::endl
			<< "> ";
		std::cin >> choice_food;
	}
	int temp = m_hunger.getLevel() + 5;
	if (temp > 10)
		m_hunger.setLevel(10);
	else m_hunger.setLevel(temp);
}

void Needs::Dance() {
	int temp = m_fun.getLevel() + 5;
	if (temp > 10)
		m_fun.setLevel(10);
	else m_fun.setLevel(temp);
}

void Needs::PlayGuitar() {
	int temp = m_fun.getLevel()  + 5;
	if (temp > 10)
		m_fun.setLevel(10);
	else m_fun.setLevel(temp);
}

void Needs::PlayComputer() {
	int temp = m_fun.getLevel() + 5;
	if (temp > 10)
		m_fun.setLevel(10);
	else m_fun.setLevel(temp);
}

void Needs::PetAnimal() {
	std::cout << "Select a pet:" << std::endl
		<< "1- Dog" << std::endl
		<< "2- Cat" << std::endl
		<< "> ";
	int pet_choice = 0;
	std::cin >> pet_choice;

	while (pet_choice > 2 || pet_choice < 1) {
		std::cout << "Please choose a real number for a real pet!" << std::endl;
		std::cin >> pet_choice;
	}

	char* buff = new char[20];

	std::cout << "Please choose a Name: ";

	std::cin >> buff;

	char* kind = new char[10];
	char* name = new char[strlen(buff) + 1];
	strncpy(name, buff, strlen(buff) + 1);

	Animal* pet_dog = new Animal(name, "Dog");
	Animal* pet_cat = new Animal(name, "Cat");

	int temp = m_fun.getLevel() + 5;
	if (temp > 10)
		m_fun.setLevel(10);
	else m_fun.setLevel(temp);

	if (pet_choice == 1) {
		std::cout << "Nice job! You pet a " << pet_dog->getKind() << ". The name is " << pet_dog->getName() << std::endl;
	}
	
	if (pet_choice == 2) {
		std::cout << "Nice job! You pet a " << pet_cat->getKind() << ". The name is " << pet_cat->getName() << std::endl;
	}
}

void Needs::Shower() {
	int temp = m_hygiene.getLevel() + 5;
	if (temp > 10)
		m_hygiene.setLevel(10);
	else m_hygiene.setLevel(temp);
}
//------End of doing something------//
void Needs::DropOne() {
	int bladerlvl = m_bladder.getLevel();
	int energylvl = m_energy.getLevel();
	int sociallvl = m_social.getLevel();
	int funlvl = m_fun.getLevel();
	int hungerlvl = m_hunger.getLevel();
	int hygienelvl = m_hygiene.getLevel();
	if (bladerlvl > 0)
		m_bladder.setLevel(bladerlvl - 1);
	if (energylvl > 0)
		m_energy.setLevel(energylvl - 1);
	if (sociallvl > 0)
		m_social.setLevel(sociallvl - 1);
	if (funlvl > 0)
		m_fun.setLevel(funlvl - 1);
	if (hungerlvl > 0)
		m_hunger.setLevel(hungerlvl - 1);
	if (hygienelvl)
		m_hygiene.setLevel(hygienelvl - 1);
}