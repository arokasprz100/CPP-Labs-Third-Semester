#include "PointAverageFunctor.h"
#include <iostream>

CPointAverageFunctor& CPointAverageFunctor::operator () (const CPoint2D& added)
{
	double sum = aver_x*counter + added.GetX();
	aver_x = sum/(counter+1);

	sum = aver_y*counter + added.GetY();
	aver_y = sum/(counter+1);

	counter++;

	return *this;
}

void CPointAverageFunctor::Print() const
{
	std::cout<<"Average Point:: ("<<aver_x<<","<<aver_y<<")"<<std::endl;
}


void CPointAverageFunctor::Reset()
{
	aver_x = 0.0;
	aver_y = 0.0;
	counter = 0;
}