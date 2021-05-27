// This is the interface file ProjCircle.h
// This is the interface for the class Circle
// which derives from the class Shape.

#ifndef PROJCIRCLE_H
#define PROJCIRCLE_H
#include "ProjShape.h"

namespace shapeshampton
{
	class Circle : public Shape
	{
	public:
		// Constructors
		Circle();
		Circle(int theRadius);

		// Getter
		double getRadius();

		// Setter
		void setRadius(int newRadius);

		virtual double getArea();
		// returns the area of the circle based on the size of the radius.
		virtual void print();
		// Prints the radius and area of the circle.
	private:
		int radius;
	};

} //shapeshampton
#endif // PROJCIRCLE_H
