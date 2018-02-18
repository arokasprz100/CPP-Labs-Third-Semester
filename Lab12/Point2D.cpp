#include "Point2D.h"

#include <iostream>

CPoint2D operator+ (double value, const CPoint2D& added)
{
	return CPoint2D (added.GetX()+value, added.GetY()+value);
}


CPoint2D CPoint2D::operator+ (const CPoint2D& added)
{
	return CPoint2D (x+added.x, y+added.y);
}

CPoint2D CPoint2D::operator- (const CPoint2D& rhs)
{
	return CPoint2D (x-rhs.x, y-rhs.y);
}

void CPoint2D::Print() const
{
	std::cout<<"Point:: ("<<x<<","<<y<<")"<<std::endl;

}