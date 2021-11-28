
#include <cmath>
#include <iostream>

#include "Simulation.hpp"
#include "Summary.hpp"

const std::string CSVPath = "/projects/python/elevators/elevators_data_large.csv";

Summary runSim(int numElevators, int numFloors, int elevatorSpeed)
{
    Simulation sim(numElevators, numFloors, elevatorSpeed, CSVPath);
    Summary results = sim.run();
    std::cout << "\tSimulation results: " << results << std::endl;
    return results;
}


float computePercentDecrease(float initial, float after)
{
    // formula from: https://www.omnicalculator.com/math/percentage-decrease
    return (-100 * ((after - initial)/std::abs(initial)));
}

int main()
{
    // sim run before speedup
    std::cout << "Before speedup:" << std::endl;
    Summary resultsOne = runSim(4, 100, 10);

    // sim run after speedup
    std::cout << "After speedup:" << std::endl;
    Summary resultsTwo = runSim(4, 100, 5);

    float waitTimePercentDecrease = computePercentDecrease(resultsOne.mAverageTimeSpentWaiting, resultsTwo.mAverageTimeSpentWaiting);
    float travelTimePercentDecrease = computePercentDecrease(resultsOne.mAverageTimeSpentTravelling, resultsTwo.mAverageTimeSpentTravelling);

    std::cout << "Wait time percent decrease: " << waitTimePercentDecrease << "%" << std::endl;
    std::cout << "Travel time percent decrease: " << travelTimePercentDecrease << "%" << std::endl;

    return 0;
}