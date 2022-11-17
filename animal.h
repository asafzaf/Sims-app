#include "food.h"

class Animal {
private:
	char* m_name;
	char* m_kind;
public:
	Animal(char* name, char* kind);
	void Eat(Food& food);
};
