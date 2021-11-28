
from simulation import Simulation

def run_sim(num_elevators, num_floors, elevator_speed):
    print("Running simulation with {} elevators, {} floors, and an elevator speed of {} seconds per floor".format(
        num_elevators, num_floors, elevator_speed
    ))

    sim = Simulation(num_elevators, num_floors, elevator_speed)
    results = sim.run()
    print("Results: {}".format(results))

if __name__ == "__main__":

    run_sim(1, 100, 10)

    run_sim(4, 100, 10)

    run_sim(4, 100, 5)
