class vehicle_data:
    def __init__(self,start,deadline,leave,gate):
        self.entry = start
        self.deadline = deadline - start
        self.exit = leave
        self.gate = gate
        self.directions = []
        self.path = []

class node:
    def __init__(self):
        self.next_state = {}
        self.is_terminal_state = 0
        self.occupied = 0
