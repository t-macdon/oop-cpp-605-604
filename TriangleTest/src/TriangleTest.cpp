//============================================================================
// Name        : TriangleTest.cpp
// Author      : Michael Schumacher && Tyler MacDonald
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : This program reads three integer values. The three values are interpreted
//   as representing the integer lengths of the sides of a triangle. This program prints a
// 	 message that states whether the triangle is equilateral (three side equal), isosceles
//   (two side equal) or scalene (no side equal).
//============================================================================

#include <cstdlib>
#include <iostream>

#include "Triangle.h"

class Triangle;

using namespace std;

/**
 * Displays a usage message to the console
 */
void printUsage() {
	cout << "Example Usage: TriangleText.exe 3.4 5 65" << endl;
}


int main(int argc, char** argv) {
	cout << "Welcome to TriangleTest!" << endl;

	// error check: 3 arguments were passed in
	if ( argc != 4 )
	{
		cout << "ERROR: Expected 3 arguments." << endl;
		printUsage();
		return 1;
	}

	// TODO: Some sort of check that these are actually ints and not something like strings
	//	A try catch won't do the trick because atoi converts chars to ints
	int sideOne = atoi(argv[1]);
	int sideTwo = atoi(argv[2]);
	int sideThree = atoi(argv[3]);

	// create a Triangle object
	Triangle triangle(sideOne, sideTwo, sideThree);

	// print TriangleType to console
	cout << "Triangle is " << triangle.getTriangleTypeAsString() << endl;

	cout << "Bye!" << endl;
	return 0;
}
