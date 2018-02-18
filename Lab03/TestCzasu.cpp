#include "Czas.h"
#include <cmath>

int main()
{
	if (fabs(Czas()-1./3.)<0.01)
		return 0;
	else
		return -1;	
}