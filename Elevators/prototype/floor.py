
from passenger import Passenger

class Floor:

    def __init__(self, id):
        self.id = id
        self.passenger_queue = []

    def add_passenger(self, target_floor):
        self.passenger_queue.append(Passenger(self.id, target_floor))
