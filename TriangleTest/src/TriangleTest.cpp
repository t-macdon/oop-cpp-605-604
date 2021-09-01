//============================================================================
// Name        : TriangleTest.cpp
// Author      : 
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : This program reads three integer values. The three values are interpreted
//   as representing the integer lengths of the sides of a triangle. This program prints a
// 	 message that states whether the triangle is equilateral (three side equal), isosceles
//   (two side equal) or scalene (no side equal).
//============================================================================

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	cout << "Welcome to TriangleTest!" << endl;

	// error check: 3 arguments were passed in
	if ( argc != 4 )
	{
		cout << "ERROR: Expected 3 arguments." << endl;
		cout << "Example Usage: TriangleText.exe 3.4 5 65" << endl;
		return 1;
	}


	// TODO: Some sort of check that these are actually ints and not something like strings
	//	A try catch won't do the trick because atoi converts chars to ints
	int side_one = atoi(argv[1]);
	int side_two = atoi(argv[2]);
	int side_three = atoi(argv[3]);

	// equilateral check
	if ( side_one == side_two && side_one == side_three && side_two == side_three )
	{
		cout << "Triangle is equilateral." << endl;
		return 0;
	}

	// isosceles check
	// we can assume it is not equilateral at this point
	if ( side_one == side_two || side_one == side_three || side_two == side_three )
	{
		cout << "Triangle is isosceles." << endl;
		return 0;
	}

	// if it's not equilateral or isosceles, it has to be scalene
	cout << "Triangle is scalene." << endl;
	return 0;
}
