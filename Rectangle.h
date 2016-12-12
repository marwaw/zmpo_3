#pragma once
#include "Point2D.h"
#include <cmath>
#include <algorithm>
#include <string>
using std::string;
using std::to_string;
using std::min;
using std::max;


class CRectangle
{
private:
	CPoint2D point1;
	CPoint2D point2;

public:
	CRectangle(double x1, double y1, double x2, double y2);
	CRectangle(const CPoint2D &p1, const CPoint2D &p2);
	CRectangle(const CRectangle &other_rectangle);

	CRectangle& operator=(CRectangle &other_rectangle);
	CRectangle& operator+(CPoint2D &point);
	CRectangle& operator+(CRectangle &other_rectangle);

	double rec_area();
	string info();

};