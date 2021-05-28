// This is the interface file ProjRectangle.h
// It is the header for the Rectangle class
// which derives from the Shape class.
#ifndef PROJRECTANGLE_H
#define PROJRECTANGLE_H
#include "ProjShape.h"

namespace shapeshampton
{
	class Rectangle : public Shape
	{
	public:
		// Constructors
		Rectangle();
		Rectangle(int theWidth, int theHeight);

		// Getters
		int getWidth();
		int getHeight();

		// Setters
		void setWidth(int newWidth);
		void setHeight(int newHeight);

		virtual double getArea();
		// returns the area of the rectangle.

		virtual void print();
		// Prints the width, height, and the area of the rectangle.
	private:
		int width;
		int height;
	};

} //shapeshampton
#endif // !PROJRECTANGLE_H
