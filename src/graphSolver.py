from objects import *

def next_dir(current_dir,next_point):
    if (current_dir == "right") or (current_dir == "right_s"):
        if (next_point == "right"):
            return "straight"
        elif (next_point == "left"):
            return "reverse"
        elif (next_point == "up"):
            return "left"
        elif (next_point == "up_s"):
            return "left_s"
        elif (next_point == "down_s"):
            return "right_s"
        else:
            return "right"
    elif (current_dir == "left") or (current_dir == "left_s"):
        if (next_point == "right"):
            return "reverse"
        elif (next_point == "left"):
            return "straight"
        elif (next_point == "up"):
            return "right"
        elif (next_point == "up_s"):
            return "right_s"
        elif (next_point == "down_s"):
            return "left_s"
        else:
            return "left"
    elif (current_dir == "up") or (current_dir == "up_s"):
        if (next_point == "right"):
            return "right"
        elif (next_point == "left"):
            return "left"
        elif (next_point == "up"):
            return "straight"
        else:
            return "reverse"
    else:
        if (next_point == "right"):
            return "left"
        elif (next_point == "left"):
            return "right"
        elif (next_point == "up"):
            return "reverse"
        else:
            return "straight"


            
def send_instructions(vehicles):
    file = open("schedule.txt","w")
    for entries in vehicles:
        vehicle = vehicles[entries]
        file.write(entries+" ")
        file.write(str(vehicle.entry) + " ")
        file.write(str(vehicle.exit) + " ")
        file.write(str(vehicle.deadline+vehicle.entry) + " ")
        file.write(str(vehicle.gate) + " ")
        for node in vehicle.path:
            file.write(str(node)+" ")
        file.write("-1 ")
        for direction in vehicle.directions:
            if (direction == "straight"):
                file.write("1 ")
            elif (direction == "left_s"):
                file.write("2 ")
            elif (direction == "right_s"):
                file.write("3 ")
            elif (direction == "left"):
                file.write("4 ")
            elif (direction == "right"):
                file.write("5 ")
            else :
                file.write("0")
        file.write("\n")

def solveGraph(graph, vehicles):
    sorted_vehicles = dict(sorted(vehicles.items(),key = lambda x : x[1].deadline))    
    for vehicle in sorted_vehicles.items():
        path,curr = getPath(vehicle[1],graph)
        directions = []
        for i in range(len(path)-1):
            next_pt = list(graph[path[i]].next_state.keys())[list(graph[path[i]].next_state.values()).index(path[i+1])]
            directions.append(next_dir(curr,next_pt))
            curr = next_pt
        directions.append("park")
        vehicle[1].directions = directions
        vehicle[1].path = path
                
        print(vehicle[0],":",path,directions)


def getPath(vehicle,graph):
    start_node = vehicle.gate + 95
    if (start_node > 97):
        curr = "left"
    else:
        curr = "right"
    path = bfs(graph,start_node)
    return path,curr
    
def bfs(graph,start):
    visited = [False] * len(graph)
    prev = [-1] * len(graph)

    queue = []
    path = []

    queue.append(start)
    visited[start] = True

    while queue:

        s = queue.pop(0)
        if (s > 56 and s <= 95):
            graph[s].occupied = 1
            path.append(s)
            while (prev[s] != start):
                s = prev[s]
                path.append(s)
            break

        for i in graph[s].next_state.values():
            if visited[i] == False and graph[i].occupied == 0:
                queue.append(i)
                prev[i] = s
                visited[i] = True
    path.append(start)
    return list(reversed(path))
