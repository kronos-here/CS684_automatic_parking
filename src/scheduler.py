from objects import *
from graphGenerator import *
from graphSolver import *

def main():
    nodes = createGraph()
    vehicles = readFile("Vehicle_handler.txt")
    getObstacles(nodes)
    solveGraph(nodes,vehicles)
    send_instructions(vehicles)

if (__name__ == '__main__'):
    main()