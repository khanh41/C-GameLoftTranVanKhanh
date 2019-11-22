#include "MyPoint.h"

MyPoint::MyPoint()
{
	this->mPosX = 0;
	this->mPosY = 0;
}

MyPoint::MyPoint(int x, int y)
{
	this->mPosX = x;
	this->mPosY = y;
}

MyPoint::MyPoint(const MyPoint& p)
{
	this->mPosX = p.mPosX;
	this->mPosY = p.mPosY;
}

MyPoint::~MyPoint()
{
}

void MyPoint::Display()
{
	cout << "Position x: " << this->mPosX;
	cout << "Position y: " << this->mPosY;
}

void MyPoint::SetX(int x)
{
	this->mPosX = x;
}

int MyPoint::GetX()
{
	return this->mPosX;
}

void MyPoint::SetY(int y)
{
	this->mPosY = y;
}

int MyPoint::GetY()
{
	return this->mPosY;
}

float MyPoint::Distance(MyPoint p)
{
	return sqrt((this->mPosX- p.mPosX)* (this->mPosX - p.mPosX)
		+ (this->mPosY- p.mPosX)* (this->mPosY - p.mPosX));
}
