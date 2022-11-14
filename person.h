#include <iostream>
#include "needs.h"
#include "job.h"

class Person {
private:
	int ID;
	char* firstName;
	char* lastName;
	Needs needs;
	Job job;
	int money;
public:
	Person(char* firstName, char* lastName);
	~Person();
};