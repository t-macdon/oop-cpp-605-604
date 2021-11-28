
class Passenger:

    def __init__(self, start_floor_id, target_floor_id):
        self.start_floor_id = start_floor_id
        self.target_floor_id = target_floor_id
        self.time_spent_waiting = 0
        self.time_spent_travelling = 0

    def __repr__(self):
        return "[startFloorID={}, targetFloorID={}, timeSpentWaiting={}, timeSpentTravelling={}]".format(
            self.start_floor_id, self.target_floor_id, self.time_spent_waiting, self.time_spent_travelling
        )
