#include "Rectangle.h"


CRectangle::CRectangle(double x1, double y1, double x2, double y2) : point1(min(x1,x2), min(y1,y2)), point2(max(x1, x2), max(y1, y2)) {}

CRectangle::CRectangle(const CPoint2D &p1, const CPoint2D &p2) : point1(p1), point2(p2) {}

CRectangle::CRectangle(const CRectangle &other_rectangle) : point1(other_rectangle.point1), point2(other_rectangle.point2) {}

CRectangle & CRectangle::operator=(CRectangle &other_rectangle)
{
	point1 = other_rectangle.point1;
	point2 = other_rectangle.point2;

	return *this;
}

CRectangle & CRectangle::operator+(CPoint2D &point)
{
	CRectangle r(min(point1.getX, point.getX), min(point1.getY, point.getY), max(point1.getX, point.getX), max(point1.getY, point.getY));
	return r;
}

CRectangle & CRectangle::operator+(CRectangle & other_rectangle)
{
	CRectangle r = *this + other_rectangle.point1;
	r = r + other_rectangle.point2;
	return r;
}

double CRectangle::rec_area()
{
	return abs(point1.getX() - point2.getX()) * abs(point1.getY() - point2.getY());
}

string CRectangle::info()
{
	return "CRectangle(CPoint" + point1.info() + ", CPoint" + point2.info() + ")";
}


