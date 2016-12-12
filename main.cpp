
#include "Rectangle.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int pointSize = 0;
	int recSize = 0;

	CPoint2D ** points = 0;
	CRectangle ** rectangles = 0;


	string command = "";

	while (command != "quit")
	{
		cin >> command;

		if (command == "go")
		{
			cout << "! " + command << endl;

			cin >> pointSize >> recSize;

			if (pointSize < 0 || recSize < 0) cout << "ERROR" << endl;
			else
			{
				points = new CPoint2D *[pointSize];
				rectangles = new CRectangle *[recSize];

				for (int i = 0; i < pointSize; i++)
				{
					points[i] = NULL;
				}

				for (int i = 0; i < recSize; i++)
				{
					rectangles[i] = NULL;
				}

				cout << "DONE" << endl;
			}

		}//if (command == "go")

		else if (command == "createPoint")
		{
			cout << "! " + command << endl;
			int pointsIn;
			double x1, y1;
			cin >> pointsIn >> x1 >> y1;

			if (pointsIn < 0 || pointsIn >= pointSize || points[pointsIn] != NULL) cout << "ERROR" << endl;
			else
			{
				points[pointsIn] = new CPoint2D(x1, y1);
				cout << "DONE" << endl;
			}

		}//else if (command == "createPoint")

		else if (command == "createPointCopy")
		{
			cout << "! " + command << endl;
			int index, indexFrom;
			cin >> index >> indexFrom;

			if (index < 0 || index >= pointSize || points[index] != NULL) cout << "ERROR" << endl;
			else
			{
				points[index] = new CPoint2D(*points[indexFrom]);
				cout << "DONE" << endl;
			}
		}//else if (command == "createPointCopy")

		else if (command == "setPoint")
		{
			cout << "! " + command << endl;

			int pointsIn;
			double x1, y1;
			cin >> pointsIn >> x1 >> y1;

			if (pointsIn < 0 || pointsIn >= pointSize || points[pointsIn] == NULL) cout << "ERROR" << endl;
			else
			{
				points[pointsIn]->setX(x1);
				points[pointsIn]->setY(y1);
				cout << "DONE" << endl;
			}

		}//else if (command == "setPoint")

		else if (command == "getPointX")
		{
			cout << "! " + command << endl;
			int index;
			cin >> index;

			if (index < 0 || index >= pointSize || points[index] == NULL) cout << "ERROR" << endl;
			else
			{
				cout << "X = " + to_string(points[index]->getX()) << endl;
				cout << "DONE" << endl;
			}
		}//else if (command == "getPointX")

		else if (command == "getPointY")
		{
			cout << "! " + command << endl;
			int index;
			cin >> index;

			if (index < 0 || index >= pointSize || points[index] == NULL) cout << "ERROR" << endl;
			else
			{
				cout << "Y = " + to_string(points[index]->getY()) << endl;
				cout << "DONE" << endl;
			}
		}//else if (command == "getPointY")

		else if (command == "createRectPoints")
		{
			cout << "! " + command << endl;

			int recIndex, point1, point2;
			cin >> recIndex >> point1 >> point2;

			if (recIndex < 0 || recIndex >= recSize || rectangles[recIndex] != NULL) cout << "ERROR" << endl;
			else
			{
				rectangles[recIndex] = new CRectangle(points[point1], points[point2]);
				cout << "DONE" << endl;
			}

		} //else if (command == "createRectPoints")

		else if (command == "createRectDouble")
		{
			cout << "! " + command << endl;

			int rec_index;
			double x1, y1, x2, y2;
			cin >> rec_index >> x1 >> y1 >> x2 >> y2;

			if (rec_index < 0 || rec_index >= recSize || rectangles[rec_index] != NULL) cout << "ERROR" << endl;
			else
			{
				rectangles[rec_index] = new CRectangle(x1, y1, x2, y2);
				cout << "DONE" << endl;
			}

		} //else if (command == "createRectDouble")

		else if (command == "createRectCopy")
		{
			cout << "! " + command << endl;

			int rec_index, rec_to_copy;
			cin >> rec_index >> rec_to_copy;

			if (rec_index < 0 || rec_index >= recSize || rectangles[rec_index] != NULL) cout << "ERROR" << endl;
			else
			{
				rectangles[rec_index] = new CRectangle(*rectangles[rec_to_copy]);
				cout << "DONE" << endl;
			}

		} //else if (command == "createRectCopy")

		else if (command == "fieldRect")
		{
			cout << "! " + command << endl;

			int rec_index;
			cin >> rec_index;

			if (rec_index < 0 || rec_index >= recSize || rectangles[rec_index] == NULL) cout << "ERROR" << endl;

			else
			{
				cout << "Pole prostokata:" + to_string(rectangles[rec_index]->rec_area()) << endl;
				cout << "DONE" << endl;
			}

		}//else if (command == "fieldRect")

		else if (command == "showRect")
		{
			cout << "! " + command << endl;

			int rec_index;
			cin >> rec_index;

			if (rec_index < 0 || rec_index >= recSize || rectangles[rec_index] == NULL) cout << "ERROR" << endl;

			else
			{
				cout << rectangles[rec_index]->info() << endl;
				cout << "DONE" << endl;
			}


		}//else if (command == "showRect")

		else if (command == "deleteAll" || command == "quit")
		{
			for (int i = 0; i < pointSize; i++)
			{
				if (points[i])
				{
					delete points[i];
					points[i] = NULL;
				}
			}

			for (int i = 0; i < recSize; i++)
			{
				if (rectangles[i])
				{
					delete rectangles[i];
					rectangles[i] = NULL;
				}
			}

			if (command == "quit")
			{
				delete[] points;
				points = NULL;

				delete[] rectangles;
				rectangles = NULL;
			}
			cout << "done" << endl;
		}//else if (command == "deleteAll" || command == "quit")

	}//while (command != "quit")

	cin.ignore();
	return 0;
}