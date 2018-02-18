#include "Point2DSmartPtr.h"

CPoint2DSmartPtr::CPoint2DSmartPtr (CPoint2D* point)
{
	ptrToPoint = point;
}

CPoint2DSmartPtr::~CPoint2DSmartPtr()
{
	delete ptrToPoint;
}

CPoint2D* CPoint2DSmartPtr::operator-> ()
{
	return ptrToPoint;
}

CPoint2D& CPoint2DSmartPtr::operator* ()
{
	return *ptrToPoint;
}
