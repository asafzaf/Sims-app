#include "food.h"

class Animal {
private:
	char* m_name;
	const char* m_kind;
public:
	Animal(char* name, const char* kind);
	char* getName() { return m_name; }
	const char* getKind() { return m_kind; }
};