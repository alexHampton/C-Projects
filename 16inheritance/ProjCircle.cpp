// This is the implementation file ProjCircle.cpp
// This implements the header file ProjCircle.h.
#include <iostream>
#include "ProjCircle.h"

namespace shapeshampton
{
	Circle::Circle() : Shape("Circle"), radius(0)
	{}
	Circle::Circle(int theRadius) : Shape("Circle"), radius(theRadius)
	{}

	void Circle::setRadius(int newRadius)
	{
		this->radius = newRadius;
	}
	double Circle::getRadius()
	{
		return radius;
	}
	double Circle::getArea()
	{
		return 3.14159 * radius * radius;
	}
	void Circle::print()
	{
		Shape::print();
		cout << "It has a radius of " << radius <<
			" and an area of " << getArea() << ".\n\n";
	}
} //shapeshampton