
class Event:

    def __init__(self, start_time, start_floor, end_floor):
        self.start_time = start_time
        self.start_floor = start_floor
        self.end_floor = end_floor

    def __repr__(self):
        return "[start_time={}, start_floor={}, end_floor={}]".format(self.start_time, self.start_floor, self.end_floor)