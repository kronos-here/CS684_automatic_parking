from objects import *

# Grah with 100 nodes
def createGraph():
    nodes = [node() for i in range(100)]
    nodes[0].next_state = {"down_s":1,"left":96,"right":7}
    nodes[6].next_state = {"up_s":5,"left":97,"right":13}
    nodes[49].next_state = {"down_s":50,"left":42,"right":98}
    nodes[55].next_state = {"up_s":54,"left":48,"right":99}
    nodes[96].next_state = {"right":0}
    nodes[97].next_state = {"right":6}
    nodes[98].next_state = {"left":49}
    nodes[99].next_state = {"left":55}
    for i in range(7,49,7):
        nodes[i].next_state = {"left":i-7,"right":i+7,"down_s":i+1}
    for i in range(13,49,7):
        nodes[i].next_state = {"left":i-7,"right":i+7,"up_s":i-1}
    for x in range(4):
        for i in range(1+14*x,6+14*x):
            nodes[i].next_state = {"left":i+55-4*x,"right":i+7,"up":i-1,"down":i+1}
        for i in range(8+14*x,13+14*x):
            nodes[i].next_state = {"right":i+53-4*x,"left":i-7,"up":i-1,"down":i+1}
        for i in range(56+10*x,61+10*x):
            nodes[i].next_state = {"right":i-55+4*x}
            nodes[i].is_terminal_state = 1
        for i in range(61+10*x,66+10*x):
            nodes[i].next_state = {"left":i-53+4*x}
            nodes[i].is_terminal_state = 1

    return nodes

def getObstacles(nodes):
    obsfile = open("obstacles.txt")
    for obstacle in obsfile:
        nodes[int(obstacle.split()[0])].occupied = 1


def readFile(filepath):
    f = open(filepath,"r")
    
    line = f.readline()
    line = f.readline()
    vehicles = {}
    for x in f:
        line = f.readline()
        if ("-----" in line) or (line.split() == []):
            continue
        line = line.split()
        vehicles[line[1]] = vehicle_data(int(line[3]),int(line[5]),int(line[7]),int(line[9]))

    # for vehicle in vehicles.values():
        # print(vehicle.gate,vehicle.entry,vehicle.exit,vehicle.deadline)

    return vehicles