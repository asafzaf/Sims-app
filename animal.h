#include <iostream>
#include "food.h"

class Animal {
private:
	char* name;
	char* kind;
public:
	Animal(char* name, char* kind);
	void Eat(Food food);
};
