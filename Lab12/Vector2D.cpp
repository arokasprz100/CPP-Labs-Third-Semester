#include "Vector2D.h"



double CVector2D::operator*(const CVector2D& rhs)
{
	return (end.GetX() - start.GetX())*(rhs.end.GetX() - rhs.start.GetX()) +
	 (end.GetY() - start.GetY())*(rhs.end.GetY() - rhs.start.GetY());
}

CVector2D::CVector2D (const CPoint2D& newStart, const CPoint2D& newEnd)
{
	start = newStart;
	end = newEnd;
}