//This is the interface file ProjShape.h
//This is the interface for the class Shape
#ifndef PROJSHAPE_H
#define PROJSHAPE_H
#include <string>
using namespace std;

namespace shapeshampton
{
	class Shape
	{
	public:
		// Constructors:
		Shape();
		Shape(string name);

		// Getter:
		string getName();

		// Setter:
		void setName(string newName);
		
		virtual double getArea();
		// sets area to 0. Redefined in Derived classes.

		virtual void print();
		// Prints shape name. Redefined in Derived classes.
	private:
		string name;
	};
} //shapeshampton

#endif // !PROJSHAPE_H
