// This is the implementation file for the Rectangle class.
// This implements the header file ProjRectangle.h
#include <iostream>
#include "ProjRectangle.h"

namespace shapeshampton
{
	Rectangle::Rectangle() : Shape("Rectangle"), width(0), height(0) {}
	Rectangle::Rectangle(int theWidth, int theHeight)
		: Shape("Rectangle"), width(theWidth), height(theHeight) {}

	int Rectangle::getWidth() { return width; }
	int Rectangle::getHeight() { return height; }

	void Rectangle::setWidth(int newWidth) { width = newWidth; }
	void Rectangle::setHeight(int newHeight) { height = newHeight; }

	double Rectangle::getArea()
	{
		return width * height;
	}
	void Rectangle::print()
	{
		Shape::print();
		cout << "It has a width of " << width << " and a height of " << height << ".\n"
			<< "The area is " << getArea() << ".\n\n";
	}

}//shapeshampton