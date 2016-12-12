#include "Point2D.h"

void CPoint2D::v_copy_points(const CPoint2D &other_point)
{
	p_coordx = new double(*other_point.p_coordx);
	p_coordy = new double(*other_point.p_coordy);
}

CPoint2D::CPoint2D(double dx, double dy)
{
	p_coordx = new double(dx);
	p_coordy = new double(dy);
}

CPoint2D::CPoint2D(const CPoint2D &other_point)
{
	v_copy_points(other_point);
}

CPoint2D &CPoint2D::operator=(CPoint2D &other_point)
{
	delete p_coordx;
	delete p_coordx;

	v_copy_points(other_point);
	return *this;
}

double CPoint2D::getX()
{
	return *p_coordx;
}

double CPoint2D::getY()
{
	return *p_coordy;
}

void CPoint2D::setX(double dx)
{
	*p_coordx = dx;
}

void CPoint2D::setY(double dy)
{
	*p_coordy = dy;
}

string CPoint2D::info()
{
	return "(" + to_string(getX()) + "," + to_string(getY()) + ")";
}

CPoint2D::~CPoint2D()
{
	delete p_coordx;
	delete p_coordy;
}
