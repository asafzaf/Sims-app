#include "food.h"

Food::Food(char* name, int worth, bool HaveToBeCooked) {
	m_name = name;
	m_worth = worth;
	m_haveToBeCooked = HaveToBeCooked;
}