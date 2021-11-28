
import time

from elevator import Elevator
from floor import Floor
from summary import Summary
from utilities import Utilities


EVENTS_PATH = r"/projects/python/elevators/elevators_data_small.csv"


class Simulation:

    def __init__(self, number_elevators, number_floors, elevator_speed):
        
        # create elevators
        self.elevator_list = []
        for _ in range(number_elevators):
            self.elevator_list.append(Elevator(elevator_speed))

        # create floors
        self.floor_list = []
        for i in range(number_floors):
            self.floor_list.append(Floor(i))

        # load all events into queue
        self.event_queue = Utilities.load_events_from_csv(EVENTS_PATH)

        self.elapsed_simulation_time = 0

        self.time_spent_waiting_list = []
        self.time_spent_travelling_list = []

    def run(self):
        # blurb
        print("Running...")
        print("{} Elevators".format(len(self.elevator_list)))
        print("{} Floors".format(len(self.floor_list)))
        print("{} Passengers".format(len(self.event_queue)))

        # loop
        while(self.is_simulation_running()):

            print("Time={}".format(self.elapsed_simulation_time))

            # see if we should handle event
            if len(self.event_queue) > 0:
                next_event = self.event_queue[0]
                if next_event.start_time <= self.elapsed_simulation_time:
                    print("Adding event: {}".format(next_event))
                    self.floor_list[next_event.start_floor].add_passenger(next_event.end_floor)
                    self.event_queue.pop(0)

            # update all elevators
            count = 0
            for elevator in self.elevator_list:
                elevator.update(self)
                print("Elevator {}: {}".format(count, elevator))
                count += 1

            # update time spent waiting for passengers on all floors
            for floor in self.floor_list:
                for passenger in floor.passenger_queue:
                    passenger.time_spent_waiting += 1

            self.elapsed_simulation_time += 1
            #time.sleep(0.1)

        print("Exiting")
        return Summary(
            sum(self.time_spent_waiting_list)/len(self.time_spent_waiting_list),
            sum(self.time_spent_travelling_list)/len(self.time_spent_travelling_list),
            self.elapsed_simulation_time
        )

    def is_simulation_running(self):
        events_remaining = len(self.event_queue) != 0
        passengers_waiting = any(map(lambda floor: len(floor.passenger_queue) != 0, self.floor_list))
        passengers_travelling = any(map(lambda elevator: len(elevator.passenger_list) != 0, self.elevator_list))

        return (events_remaining or passengers_waiting or passengers_travelling)
