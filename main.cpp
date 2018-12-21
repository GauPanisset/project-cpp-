#include "card.h"
#include <iostream>

using namespace std;

int main()
{
	Card carte("Paris","France");
	carte.displayCard();
	carte.swapCard();

	return 0;
}
