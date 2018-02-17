#include <iostream>

#include "PrintListContent.h"

void PrintListContent (int numberOfStudents, char **wordsList)
{
	for (int i=0; i<numberOfStudents; i++)
		std::cout<<wordsList[i]<<std::endl;

}

void PrintListContent (int numberOfStudents, int *yearsList)
{
	for (int i=0; i<numberOfStudents; i++)
		std::cout<<yearsList[i]<<std::endl;

}

void PrintListContent (int numberOfStudents, char** namesList, char **surnamesList, int* yearsList)
{
	for (int i=0; i<numberOfStudents; i++)
		std::cout<<surnamesList[i]<<", "<<namesList[i]<<" - year "<<yearsList[i]<<std::endl;
}
