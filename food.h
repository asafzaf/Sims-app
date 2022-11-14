#include <iostream>

class Food {
private:
	char* name;
	int worth;
	bool haveToBeCooked;
public:
	Food(char* name, int worth, bool haveToBeCooked);
};