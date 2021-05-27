// * Application for Separate Compilation Project
// * Takes in a formatted amount of money from
// * 'infile.dat' file and creates a Money object.
// * Then outputs that Money object to 'outfile.dat' file.
// * Uses header file AlexHamptonMoney.h and 
// * interface file AlexHamptonMoney.cpp.
// *
// * Author: Alex Hampton
// */

#include <fstream>
#include <iostream>
#include "AlexHamptonMoney.h"
using namespace std;

int main()
{
	Money amount;
	ifstream inStream;
	ofstream outStream;


	// opens file 'infile.dat'. Will fail if 'infile.dat' does not exist.
	inStream.open("infile.dat");
	if (inStream.fail()) // Closes program if problem occurs
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	// opens file 'outfile.dat'. Will create the file if it does not exist.
	outStream.open("outfile.dat"); 
	if (outStream.fail())
	{
		cout << "Output file opening failed.\n";
		exit(1);
	}

	inStream >> amount;
	outStream << amount
		<< " copied from the file infile.dat.\n";
	cout << amount
		<< " copied from the file infile.dat.\n";

	inStream.close();
	outStream.close();
	system("pause");
	return 0;
}