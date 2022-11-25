#include "food.h"

Food::Food(const char* name, int worth, bool HaveToBeCooked) {
	m_name = name;
	m_worth = worth;
	m_haveToBeCooked = HaveToBeCooked;
}