
from elevator_states import ElevatorStates

class Elevator:

    def __init__(self, seconds_between_floors):
        self.capacity = 8
        self.speed = seconds_between_floors
        self.state = ElevatorStates.STOPPED
        self.current_floor = 0
        self.target_floor = 0
        self.passenger_list = []
        self.time_spent_moving = 0

    def __repr__(self):
        return "[currentFloor={}, targetFloor={}, numPassengers={}, passengerList={}]".format(
            self.current_floor, self.target_floor, len(self.passenger_list), self.passenger_list
        )

    def update(self, simulation):
        # update time spent travelling for all passengers
        for passenger in self.passenger_list:
            passenger.time_spent_travelling += 1

        # now handle state
        if self.state == ElevatorStates.STOPPED:
            self._handle_stopped_state(simulation)
        elif self.state == ElevatorStates.STOPPING:
            self._handle_stopping_state(simulation)
        elif self.state == ElevatorStates.MOVING_DOWN:
            self._handle_moving_down_state()
        elif self.state == ElevatorStates.MOVING_UP:
            self._handle_moving_up_state()
    
    def _handle_stopped_state(self, simulation):
        print("Handling STOPPED state")
        # check if we have passengers that can leave
        passengers_to_remove = []
        for passenger in self.passenger_list.copy():
            if passenger.target_floor_id == self.current_floor:
                passengers_to_remove.append(passenger)
        
        if len(passengers_to_remove) > 0:
            print("Removing these passengers: {}".format(passengers_to_remove))

        for p in passengers_to_remove:
            simulation.time_spent_waiting_list.append(p.time_spent_waiting)
            simulation.time_spent_travelling_list.append(p.time_spent_travelling)
            self.passenger_list.remove(p)

        # pick up new passengers if applicable
        while len(self.passenger_list) < self.capacity and len(simulation.floor_list[self.current_floor].passenger_queue) > 0:
            floor_passenger = simulation.floor_list[self.current_floor].passenger_queue.pop(0)
            print("Picking up passenger: {}".format(floor_passenger))
            self.passenger_list.append(floor_passenger)

        # if we are at our target, choose a new target if applicable
        if self.current_floor == self.target_floor:
            print("At our target, so reevaluating movement")
            # revaluate movement
            # if we have passengers, go to the target floor of the first in queue
            if len(self.passenger_list) > 0:
                first_passenger = self.passenger_list[0]
                self.target_floor = first_passenger.target_floor_id
            else:
                # see if we can go pick up a passenger
                next_target = self._get_first_floor_with_waiting_passengers(simulation.floor_list)
                if next_target != -1:
                    self.target_floor = next_target
        
        self.state = self._determine_direction()

    def _handle_stopping_state(self, simulation):
        pass

    def _handle_moving_down_state(self):
        print("Handling MOVING_DOWN state")
        self.time_spent_moving += 1
        if self.time_spent_moving % self.speed == 0:
            # we've made it to a new floor
            self.current_floor -= 1
            self.time_spent_moving = 0
            self._handle_new_floor()

    def _handle_moving_up_state(self):
        print("Handling MOVING_UP state")
        self.time_spent_moving += 1
        if self.time_spent_moving % self.speed == 0:
            # we've made it to a new floor
            self.current_floor += 1
            self.time_spent_moving = 0
            self._handle_new_floor()

    def _handle_new_floor(self):
        # process the current floor
        if self.current_floor == self.target_floor:
            # stop the elevator if we have arrived
            self.state = ElevatorStates.STOPPED
        else:
            # if any passengers can get off on this floor, stop the elevator
            for passenger in self.passenger_list:
                if passenger.target_floor_id == self.current_floor:
                    self.state = ElevatorStates.STOPPED

    def _determine_direction(self):
        if self.current_floor < self.target_floor:
            return ElevatorStates.MOVING_UP
        elif self.current_floor > self.target_floor:
            return ElevatorStates.MOVING_DOWN
        else:
            return ElevatorStates.STOPPED

    def _get_first_floor_with_waiting_passengers(self, floor_list):
        for floor in floor_list:
            if len(floor.passenger_queue) != 0:
                return floor.id
        return -1
