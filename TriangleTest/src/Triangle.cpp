/*
 * Triangle.cpp
 *
 *  Created on: Sep 1, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */
#include "Triangle.h"

/**
 * Constructor
 *
 * @param sideOne A unique side of the triangle
 * @param sideTwo A unique side of the triangle
 * @param sideThree A unique side of the triangle
 * @return A Triangle object
 */
Triangle::Triangle(int sideOne, int sideTwo, int sideThree)
{
    this->sides[0] = sideOne;
    this->sides[1] = sideTwo;
    this->sides[2] = sideThree;
    this->triangleType = determineTriangleType(sides);
}

/**
 * Counts the number of matching sides and returns the appropriate triangle type
 *
 * @param sides An array of triangle sides
 * @return TriangleType describing the nature of the triangle
 */
Triangle::TriangleType Triangle::determineTriangleType(int sides[]) {

    // compare all sides and compute how many are matching
    int numMatches = 0;
    for (unsigned int i = 0; i < Triangle::NUM_SIDES; i++) {
        for (unsigned int j = i + 1; j < Triangle::NUM_SIDES; j++) {
            if (sides[i] == sides[j]) {
                numMatches += 1;
            }
        }
    }

    // now determine TriangleType based on number of matching sides
    if (numMatches == 0) {
        return TriangleType::SCALENE;
    } else if (numMatches == 1) {
        return TriangleType::ISOSCELES;
    } else if (numMatches == 3) {
        return TriangleType::EQUILATERAL;
    } else {
        return TriangleType::UNKNOWN;
    }
}

/**
 * @return the std::string representation of the TriangleType
 */
std::string Triangle::getTriangleTypeAsString() {
    switch(this->triangleType){
        case TriangleType::EQUILATERAL:
            return "equilateral";
        case TriangleType::ISOSCELES:
            return "isosceles";
        case TriangleType::SCALENE:
            return "scalene";
        case TriangleType::UNKNOWN:
        default:
            return "unknown";
    }
}

