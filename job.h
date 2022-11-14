#include <iostream>

class Job {
private:
	char* title;
	int salary;
	int dailyWorkHours;
public:
	Job(char* title, int salary, int dailyWorkHours);
	void GoToWork();
};