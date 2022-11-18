#pragma once

class Food {
private:
	char* m_name;
	int m_worth;
	bool m_haveToBeCooked;
public:
	Food(char* name, int worth, bool haveToBeCooked);
	int getWorth() { return m_worth; }
	void setWorth(int Worth) { m_worth = Worth; }
};