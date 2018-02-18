#include "GradeBook.h"
#include <iostream>

GradeBook::GradeBook()
{
	numberOfGrades = 0;
	gradeList = 0;
}

void GradeBook::insert (const Grade *insertedGrade)
{
	if (numberOfGrades==0)
	{
		gradeList = new const Grade * [1];
		gradeList[0] = insertedGrade;
		numberOfGrades++;
		return;
	}

	const Grade** temp = new const Grade* [numberOfGrades];
	for (int i=0; i<numberOfGrades; i++)
	{
		temp[i]=gradeList[i];
	}
	delete [] gradeList;
	gradeList = new const Grade * [numberOfGrades+1];
	for (int i=0; i<numberOfGrades; i++)
	{
		gradeList[i] = temp[i];
	}
	gradeList[numberOfGrades] = insertedGrade;
	delete [] temp;
	numberOfGrades++;
}

void GradeBook::print() const
{
	std::cout<<"Grades in the book: "<<std::endl;
	for (int i=0; i<numberOfGrades; i++)
		gradeList[i]->print();
	std::cout<<std::endl;
}

void GradeBook::addGrade (double newGrade)
{
	Grade * createdGrade = new Grade(newGrade);
	insert (createdGrade);
}

GradeBook::GradeBook(const GradeBook& copiedBook)
{
	numberOfGrades = copiedBook.numberOfGrades;
	gradeList = new const Grade * [numberOfGrades];
	for (int i=0; i<numberOfGrades; i++)
	{
		gradeList[i] = new const Grade(*copiedBook.gradeList[i]);
	}
}

void GradeBook::remove(int index)
{
	std::cout<<"Removing grade with the ID: "<<gradeList[index-1]->getID()<<std::endl;
	const Grade** temp = new const Grade *[numberOfGrades-1];

	delete gradeList[index-1];
	for (int i=0; i<index-1; i++)
	{
		temp[i]=gradeList[i];
	}
	for (int i=index; i<numberOfGrades; i++)
	{
		temp[i-1] = gradeList[i];
	}
	delete [] gradeList;


	gradeList = new const Grade * [numberOfGrades-1];
	for (int i=0; i<numberOfGrades-1; i++)
	{
		gradeList[i] = temp[i];
	}
	numberOfGrades--;
	delete [] temp;

	std::cout<<std::endl;


}


GradeBook::~GradeBook()
{
	for (int i=0; i<numberOfGrades; i++)
	{
		delete gradeList[i];
	}
	delete [] gradeList;
	gradeList = 0;

	numberOfGrades=0;
}
