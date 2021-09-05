//============================================================================
// Name        : TriangleTest.cpp
// Author      : Michael Schumacher && Tyler MacDonald
// Version     : 1.0
// Description : This program reads three integer values. The three values are interpreted
//   as representing the integer lengths of the sides of a triangle. This program prints a
// 	 message that states whether the triangle is equilateral (three side equal), isosceles
//   (two side equal) or scalene (no side equal).
//============================================================================

#include <cstdlib>
#include <cmath>
#include <array>
#include <iostream>

#include "Triangle.h"

class Triangle;

using namespace std;

/**
 * Displays a usage message to the console
 */
void printUsage() {
    cout << "Example Usage: TriangleText.exe 3 5 65" << endl;
}

int main(int argc, char** argv) {
    cout << "Welcome to TriangleTest!" << endl;

    // error check: 3 arguments were passed in
    if ( argc != Triangle::NUM_SIDES+1 )
    {
        cout << "ERROR: Expected " << Triangle::NUM_SIDES <<" arguments." << endl;
        printUsage();
        return 1;
    }

    // read command line arguments as an integer sides array
    array<int, Triangle::NUM_SIDES> sides;
    for(size_t i=0; i<sides.size(); i++) {
        try {
            float inputAsFloat = stof(argv[i+1]);
            int inputAsInt = trunc(inputAsFloat);
            if (inputAsFloat != inputAsInt) {
                cout << "Warning, truncating \"" << 
                    inputAsFloat  << "\" to \"" << 
                    inputAsInt << "\"" << endl;
            }
            sides[i] = inputAsInt;
        } catch (...) {
            // error check: if stof does not work, then the argument is not a valid number
            cout << "Unable to convert \"" << argv[i+1] << "\" to integer!" << endl;
            printUsage();
            return -1;
        }
    }

    // create a Triangle object
    try {
        Triangle triangle(sides);
        // print TriangleType to console
        cout << "Triangle is " << triangle.getTriangleTypeAsString() << "!" << endl;
        cout << "Bye!" << endl;
        return 0;
    } catch (std::invalid_argument& e) {
        cout << e.what() << endl;
        printUsage();
        return -1;
    }
}
