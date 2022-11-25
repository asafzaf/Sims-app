#pragma once

class Food {
private:
	const char* m_name;
	int m_worth;
	bool m_haveToBeCooked;
public:
	Food(const char* name, int worth, bool haveToBeCooked);

	const char* getName() { return m_name; }

	int getWorth() { return m_worth; }
	void setWorth(int Worth) { m_worth = Worth; }


};