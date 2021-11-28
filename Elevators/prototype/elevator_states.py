
from enum import IntEnum

class ElevatorStates(IntEnum):

    STOPPED=0,
    STOPPING=1,
    MOVING_UP=2,
    MOVING_DOWN=3
