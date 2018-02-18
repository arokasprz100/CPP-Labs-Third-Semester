#include "Point2DArray.h"

#include <iostream>
#include <cstdlib>

CPoint2DArray::CPoint2DArray (int newSize)
{
	if (newSize==0)
	{
		sizeOfArray=0;
		arrayOfPoints=0;
		return;
	}

	sizeOfArray = newSize;
	arrayOfPoints = new CPoint2D* [newSize];
	for (int i=0; i<newSize; ++i)
		arrayOfPoints[i] = new CPoint2D;
}

CPoint2DArray::CPoint2DArray (const CPoint2D& copiedPoint, int newSize)
{
	sizeOfArray = newSize;
	arrayOfPoints = new CPoint2D* [newSize];
	for (int i=0; i<newSize; ++i)
		arrayOfPoints[i] = new CPoint2D(copiedPoint);

}

CPoint2DArray::CPoint2DArray (const CPoint2DArray& copied)
{
	arrayOfPoints = new CPoint2D* [copied.sizeOfArray];
	sizeOfArray = copied.sizeOfArray;

	for (int i=0; i<sizeOfArray; ++i)
	{
		arrayOfPoints[i] = new CPoint2D (*copied.arrayOfPoints[i]);
	}

}


void CPoint2DArray::Print () const
{
	std::cout<<"Point array:: ";
	for (int i=0; i<sizeOfArray; ++i)
	{
		std::cout<<"("<<arrayOfPoints[i]->GetX()<<","<<arrayOfPoints[i]->GetY()<<") ";
	}

	std::cout<<std::endl;

}

void CPoint2DArray::FillRand(int lower, int upper)
{
	for (int i=0; i<sizeOfArray; ++i)
	{
		arrayOfPoints[i]->SetX(rand()%(upper-lower+1)+ lower);
		arrayOfPoints[i]->SetY(rand()%(upper-lower+1)+ lower);

	}

}


CPoint2DArray& CPoint2DArray::operator= (const CPoint2DArray& copied)
{
	if (this==&copied)
		return *this;

	if (arrayOfPoints!=0)
	{
		for (int i=0; i<sizeOfArray; ++i)
			delete arrayOfPoints[i];
		delete [] arrayOfPoints;
	}

	arrayOfPoints = new CPoint2D* [copied.sizeOfArray];
	sizeOfArray = copied.sizeOfArray;

	for (int i=0; i<sizeOfArray; ++i)
	{
		arrayOfPoints[i] = new CPoint2D (*copied.arrayOfPoints[i]);
	}


	return *this;
}


CPoint2DArray::~CPoint2DArray()
{
	for (int i=0; i<sizeOfArray; ++i)
		delete arrayOfPoints[i];

	delete [] arrayOfPoints;

	arrayOfPoints = 0;
	sizeOfArray = 0;
}

CPoint2D& CPoint2DArray::operator [] (int index)
{
	return *(arrayOfPoints[index]);
}