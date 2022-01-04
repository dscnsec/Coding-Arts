'''
Time Complexity: O(V+E) where V is the number of cities and E is the number of prerequisites. Time used to topological sort the graph.
Space Complexity: O(n) where n is the number of cities. Space used to store the graph / recurstion stack.
Approach:
    1. Build a graph from the given edge list
    2. Topological sort the graph
    3. Print the tour if it exists
Note: To test this against other inputs use input.txt or comment line 44 to test on OJ
'''

import sys
from collections import defaultdict

def getMapping(n,prerequisite):
    preq = []
    for x,y in prerequisites:
        preq.append([ord(x)-ord('a'),ord(y)-ord('a')])
    return preq

def findTour(n, preq):
    graph = defaultdict(list)
    for cityX, cityY in preq: 
        graph[cityY].append(cityX)
    tour, visited = [], [0] * n

    def dfs(city):
        if visited[city]:
            return visited[city] == 1
        visited[city] = -1
        for neighbor in graph[city]:
            if not dfs(neighbor):
                return False
        visited[city] = 1
        tour.append(city)
        return True

    for i in range(n):
        if not dfs(i):
            return []

    return [] if len(tour) < n else tour[::-1]

if __name__ == '__main__':
    sys.stdin = open('input.txt','r')
    n = int(input())
    prerequisites = []
    while True:
        try:
            prerequisite = input().split()
            prerequisites.append(prerequisite)
        except EOFError:
            break
    preq = getMapping(n, prerequisite)
    tour = findTour(n, preq)
    if not tour:
        print(-1)
    else:
        for city in tour:
            print(chr(city + ord('a')), end=' ')
