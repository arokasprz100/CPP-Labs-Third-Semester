#include "Grade.h"
#include <iostream>

int Grade::nextID = 1;

Grade::Grade(double newGrade)
{
	gradeValue = newGrade;
	gradeID = nextID;
	nextID++;
}

void Grade::print() const
{
	std::cout<<"Grade ID="<<gradeID<<" value="<<gradeValue<<std::endl;
}

int Grade::getID() const
{
	return gradeID;
}