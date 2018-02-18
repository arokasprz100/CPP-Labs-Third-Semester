#include "Suma.h"

int main()
{
	float suma=2000.5+3000.6;
	#ifdef FL
	float a1=2000.5;
	float a2=3000.6;
	if (suma!=Suma(a1, a2))
		return -1;
	else 
		return 0;



	#endif

	#ifdef IN
	int b1=2000.5;
	int b2=3000.6;
	if (suma!=Suma(b1, b2))
		return -1;
	else
		return 0;


	#endif

	#ifdef Do
	double c1=2000.5;
	double c2=3000.6;
	if (suma!=Suma(c1, c2))
		return -1;
	else
		return 0;


	#endif

	#ifdef Ch
	char d1=2000.5;
	char d2=3000.6;
	if (suma!=Suma(d1, d2))
		return -1;
	else
		return 0;


	#endif


}
