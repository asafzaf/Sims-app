#pragma once

class Job {
private:
	const char* m_title;
	int m_salary;
	int m_dailyWorkHours;
public:
	Job();
	Job(char* title, int Salary, int dailyWorkHours);

	const char* getTitle() { return m_title; }
	//void setTitle(char* Title) { m_title = Title; }

	int getSalary() { return m_salary; }
	void setSalary(int Salary) { m_salary = Salary; }

	int getDailyWorkHours() { return m_dailyWorkHours; }
	void setDailyWorkHours(int dailyWH) { m_dailyWorkHours = dailyWH; }

	void GoToWork();
};