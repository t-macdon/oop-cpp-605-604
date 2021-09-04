/*
 * Triangle.cpp
 *
 *  Created on: Sep 1, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */
#include "Triangle.h"
#include <stdexcept>

Triangle::Triangle(const std::array<int, NUM_SIDES>& sides)
{
    this->sides = sides;
    // Verify that our sides do create a valid triangle
    if (!validTriangle(this->sides)) {
        throw std::invalid_argument("These sides do not create a valid triangle");
    }
    this->triangleType = determineTriangleType(sides);
}


bool Triangle::validTriangle(const std::array<int, NUM_SIDES>& sides)
{
    bool valid = true;
    // Verify all sides are non-zero and positive
    valid = (valid
        && sides[0] > 0
        && sides[1] > 0
        && sides[2] > 0
    );

    // Verify these sides create a real triangle
    // Uses the Triangle Inequality Thereom
    valid = (valid 
        && sides[0] + sides[1] > sides[2]
        && sides[0] + sides[2] > sides[1]
        && sides[1] + sides[2] > sides[0]);

    return valid;
}

Triangle::TriangleType Triangle::determineTriangleType(const std::array<int, NUM_SIDES>& sides) {

    // compare all sides and compute how many are matching
    int numMatches = 0;
    for (unsigned int i = 0; i < sides.size(); i++) {
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

