#include "job.h"

Job::Job() {
	const char* ttl = "unemployed";
	m_title = ttl;
	m_salary = 0;
	m_dailyWorkHours = 0;
}

Job::Job(char* Title, int Salary, int DailyWorkHours) {
	m_title = Title;
	m_salary = Salary;
	m_dailyWorkHours = DailyWorkHours;
}