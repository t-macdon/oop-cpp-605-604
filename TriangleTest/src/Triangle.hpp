/*
 * Triangle.h
 *
 *  Created on: Sep 1, 2021
 *      Author:
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <list>
#include <string>

class Triangle {
public:
    static const int NUM_SIDES = 3;
    Triangle(int sidesOne, int sideTwo, int sideThree);
    virtual ~Triangle();
    std::string getTriangleTypeAsString();
    enum TriangleType {EQUILATERAL, ISOSCELES, SCALENE, UNKNOWN};
private:
    int sides[NUM_SIDES];
    TriangleType triangleType;
    TriangleType determineTriangleType(int sides[]);
};

#endif /* TRIANGLE_H_ */
