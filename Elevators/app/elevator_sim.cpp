
#include <cmath>
#include <iostream>

#include "Simulation.hpp"
#include "Summary.hpp"

/**
 * @brief Path to the CSV file containing Event data
 * 
 */
const std::string CSVPath = "/workspaces/oop-cpp-605-604/Elevators/elevators_data_large.csv";

/**
 * @brief Creates a Simulation object, runs it, then prints and returns the results
 * 
 * @param numElevators Number of Elevators to put in the Simulation
 * @param numFloors Number of Floors to put in the Simulation
 * @param elevatorSpeed Time in seconds it takes an Elevator to travel between Floors in this Simulation
 * @return Summary The Simulation results
 */
Summary runSim(int numElevators, int numFloors, int elevatorSpeed)
{
    Simulation sim(numElevators, numFloors, elevatorSpeed, CSVPath);
    Summary results = sim.run();
    std::cout << "\tSimulation results: " << results << std::endl;
    return results;
}


/**
 * @brief Computes the percent decrease between the initial and after value
 * 
 * @param initial 
 * @param after 
 * @return float Percent decrease
 */
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