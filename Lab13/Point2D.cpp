#include "Point2D.h"
#include <iostream>

void CPoint2D::Print() const
{	
	///Point:: (1.2,0.5)
	std::cout<<"Point:: ("<<m_x<<","<<m_y<<")"<<std::endl;

}

CPoint2D& CPoint2D::operator--()
{
	m_x-=1.0;
	m_y-=1.0;

	return *this;
}



CPoint2D& CPoint2D::operator++(int)
{
	m_x+=1.0;
	m_y+=1.0;

	return *this;
}

CPoint2D operator+(const CPoint2D& lhs, const CPoint2D& rhs)
{
	return CPoint2D (lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

void* CPoint2D::operator new(size_t size)
{
	std::cout<<"CPoint2D:: alokowanie "<<size<<" bajtow"<<std::endl;
	return ::new CPoint2D;
}

void CPoint2D::operator delete (void* ptr)
{
	std::cout<<"CPoint2D:: zwalnianie wskaznika "<<ptr<<std::endl;
	::delete static_cast<CPoint2D*> (ptr);
}