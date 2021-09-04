/*
 * Triangle.h
 *
 *  Created on: Sep 1, 2021
 *      Author: Michael Schumacher && Tyler MacDonald
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <string>
#include <array>

class Triangle {
public:
    // Number of sides to a triangle
    static const int NUM_SIDES = 3;
    enum TriangleType {EQUILATERAL, ISOSCELES, SCALENE, UNKNOWN};

    /**
     * @param sides An array of three sides to copy in to this triangle
     * @throw invalid_argument Sides do not create a proper triangle
     * @return A Triangle object
     */
    Triangle(const std::array<int, NUM_SIDES>& sides);

    /**
     * @return the std::string representation of the TriangleType
     */
    std::string getTriangleTypeAsString();

private:
    // Length of sides for this triangle
    std::array<int, NUM_SIDES> sides;
    TriangleType triangleType;

    /**
     * @brief Counts the number of matching sides and returns the appropriate triangle type
     * @warning Does not verify that this is a real triangle. see @ref validTriangle
     * @param sides An array of triangle sides
     * @return TriangleType describing the nature of the triangle
     */
    static TriangleType determineTriangleType(const std::array<int, NUM_SIDES>& sides);

    /** 
     * @brief Verify that the provided sides creates a real triangle
     * @param sides An array of triangle sides
     * @return true if the triangle is valid, otherwise false
     */
    static bool validTriangle(const std::array<int, NUM_SIDES>& sides);
};

#endif /* TRIANGLE_H_ */
