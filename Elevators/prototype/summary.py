
class Summary:

    def __init__(self, average_time_spent_waiting, average_time_spent_travelling, total_simulation_time):
        self.average_time_spent_waiting = average_time_spent_waiting
        self.average_time_spent_travelling = average_time_spent_travelling
        self.total_simulation_time = total_simulation_time

    def __repr__(self):
        return "[averageTimeSpentWaiting={}, averageTimeSpentTravelling={}, totalSimulationTime={}]".format(
            self.average_time_spent_waiting, self.average_time_spent_travelling, self.total_simulation_time
        )
