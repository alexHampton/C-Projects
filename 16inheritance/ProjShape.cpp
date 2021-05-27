//This is the implementation file ProjShape.cpp
//This implements the header file ProjShape.h
#include "ProjShape.h"
#include <iostream>
#include <string>
using namespace std;

namespace shapeshampton
{
	Shape::Shape()
	{
		name = "empty shape";
	}
	Shape::Shape(string name)
	{
		this->name = name;
	}
	string Shape::getName()
	{
		return this->name;
	}
	void Shape::setName(string newName)
	{
		this->name = newName;
	}
	double Shape::getArea()
	{
		return 0;
	}
	void Shape::print()
	{
		cout << "This shape is a " << name << ".\n\n";
	}
} //shapeshampton