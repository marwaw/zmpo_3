#pragma once
#include <string>
using std::string;
using std::to_string;


class CPoint2D
{

private:
	double *p_coordx;
	double *p_coordy;

	void v_copy_points(const CPoint2D &other_point);

public:
	CPoint2D(double dx, double dy);
	CPoint2D(const CPoint2D &other_point);

	CPoint2D &operator= (CPoint2D &other_point);

	double getX();
	double getY();

	void setX(double dx);
	void setY(double dy);

	string info();

	~CPoint2D();
};