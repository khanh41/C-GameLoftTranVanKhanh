#include<iostream>
#include"MyPoint.h"
using namespace std;

void main() {
	int x, y;
	// point 1 use constructor Mypoint()
	MyPoint point1;
	cout << "Position Point1(x, y): ";
	cin >> x;
	cin >> y;
	point1.SetX(x);
	point1.SetY(y);

	// point 2 use constructor Mypoint(int, int)
	cout << "Position Point2(x, y): ";
	cin >> x;
	cin >> y;
	MyPoint point2(x,y);
	cout << "Distance of Point1(" << point1.GetX() << ", " << point1.GetY()
		<< ") and Point2(" << point2.GetX() << ", " << point2.GetY() << "): " 
		<< point1.Distance(point2) << endl;
}