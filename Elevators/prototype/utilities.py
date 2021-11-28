
import csv

from event import Event


class Utilities:

    @staticmethod
    def load_events_from_csv(csv_path):
        events = []
        with open(csv_path, newline='') as fin:
            reader = csv.DictReader(fin)
            for row in reader:
                events.append(
                    Event(
                        int(row["start_time"]), 
                        int(row["start_floor"]),
                        int(row["end_floor"])
                        )
                    )
        return events
