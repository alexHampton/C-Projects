 //This is the application file InheritanceProj.cpp.
 //
 //It demonstrates the use of the Shape class,
 //and the use of the Circle and Rectangle classes which are
 //derived from the Shape class.
 //
 //**************************************
 //*     HOW THIS PROGRAM WORKS:		*
 //**************************************
 //First, objects are made from all classes using default constructors
 //Next, the same objects are updated with user input using setters.
 //Finally, new objects are initialized with the same user input.
 //
 //Author: Alex Hampton
 //04/01/2021

#include <iostream>
#include "ProjCircle.h"
#include "ProjRectangle.h"
#include "ProjShape.h"
using namespace std;
using namespace shapeshampton;

void printHeader(string varName)
{
	cout << "\n" << varName << " details:\n" << "-----------------------\n";
}

int main()
{
	Shape s1;
	Circle c1;
	Rectangle r1;

	string shapeName;
	int circleRadius, rectangleWidth, rectangleHeight;

	/*********************************************************************
	*	TEST SHAPE CLASS
	**********************************************************************/

	cout << "Shape 's1' has been created with a default constructor.\n";
	printHeader("s1");
	s1.print();
	system("pause");

	cout << "Please enter the name of any shape: ";
	cin >> shapeName;
	cout << "Shape 's1' has been updated with your shape name.\n";
	s1.setName(shapeName);	//Update Shape object
	printHeader("s1");
	s1.print();
	system("pause");

	Shape s2 = Shape(shapeName); // Initialize Shape object
	cout << "Shape 's2' has been initialized with your shape name:\n";
	printHeader("s2");
	s2.print();
	system("pause");
	system("cls");

	/*********************************************************************
	*	TEST CIRCLE CLASS
	**********************************************************************/

	cout << "Circle 'c1' has been created with a default constructor.\n";
	printHeader("c1");
	c1.print();
	system("pause");
	cout << "Please enter the radius of a circle: ";
	cin >> circleRadius;
	cout << "Circle 'c1' has been updated with your radius.\n";
	c1.setRadius(circleRadius); // Update Circle object.
	printHeader("c1");
	c1.print();
	system("pause");

	Circle c2 = Circle(circleRadius); // Initialize Circle object
	cout << "Circle 'c2' has been initialized with your radius:\n";
	printHeader("c2");
	c2.print();

	system("pause");
	system("cls");

	/*********************************************************************
	*	TEST RECTANGLE CLASS
	**********************************************************************/

	cout << "Rectangle 'r1' has been created with a default constructor.\n";
	printHeader("r1");
	r1.print();
	system("pause");
	cout << "Please enter the width and the height of a rectangle,\n"
		<< "separated by a space: ";
	cin >> rectangleWidth >> rectangleHeight;
	cout << "Rectangle 'r1' has been updated with your dimensions.\n";
	r1.setWidth(rectangleWidth); // Update Rectangle object
	r1.setHeight(rectangleHeight);
	printHeader("r1");
	r1.print();
	system("pause");

	Rectangle r2 = Rectangle(rectangleWidth, rectangleHeight); // Initialize Rectangle object
	cout << "Rectangle 'r2' has been initialized with your dimensions:\n";
	printHeader("r2");
	r2.print();

	cout << "THIS IS THE END OF THE PROGRAM.\n";
	system("pause");
	return 0;
}


/*********************************************************************
*	OUTPUT
**********************************************************************/


//Shape 's1' has been created with a default constructor.
//
//s1 details :
//---------------------- -
//This shape is a empty shape.
//
//Press any key to continue . . .
//Please enter the name of any shape : Rhombus
//Shape 's1' has been updated with your shape name.
//
//s1 details :
//---------------------- -
//This shape is a Rhombus.
//
//Press any key to continue . . .
//Shape 's2' has been initialized with your shape name :
//
//s2 details :
//---------------------- -
//This shape is a Rhombus.
//
//Press any key to continue . . .




//Circle 'c1' has been created with a default constructor.
//
//c1 details :
//---------------------- -
//This shape is a Circle.
//
//It has a radius of 0 and an area of 0.
//
//Press any key to continue . . .
//Please enter the radius of a circle : 9
//Circle 'c1' has been updated with your radius.
//
//c1 details :
//---------------------- -
//This shape is a Circle.
//
//It has a radius of 9 and an area of 254.469.
//
//Press any key to continue . . .
//Circle 'c2' has been initialized with your radius :
//
//c2 details :
//---------------------- -
//This shape is a Circle.
//
//It has a radius of 9 and an area of 254.469.
//
//Press any key to continue . . .




//Rectangle 'r1' has been created with a default constructor.
//
//r1 details :
//---------------------- -
//This shape is a Rectangle.
//
//It has a width of 0 and a height of 0.
//The area is 0.
//
//Press any key to continue . . .
//Please enter the widthand the height of a rectangle,
//separated by a space : 7 3
//Rectangle 'r1' has been updated with your dimensions.
//
//r1 details :
//---------------------- -
//This shape is a Rectangle.
//
//It has a width of 7 and a height of 3.
//The area is 21.
//
//Press any key to continue . . .
//Rectangle 'r2' has been initialized with your dimensions :
//
//r2 details :
//---------------------- -
//This shape is a Rectangle.
//
//It has a width of 7 and a height of 3.
//The area is 21.
//
//THIS IS THE END OF THE PROGRAM.
//Press any key to continue . . .