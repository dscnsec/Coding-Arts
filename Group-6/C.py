'''
Time Complexity: O(n^3) dominated by floyd-warshall, where n is the number of nodes
Space Complexity: O(n^2) space used for the adjacency matrix
Approach:
	1. Create an adjacency matrix
	2. Find the all pair shortest paths using floyd-warshall
	3. Starting from home(0) greedily pick the closest cafetaria and mark them visited
	4. Print the tour
Note: To test this against other inputs use input.txt or comment line 39 to test on OJ
'''

import sys
from math import inf

def floydWarshall(graph):
	dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
	for k in range(n):
		for i in range(n):
			for j in range(n):
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j])
	tour(dist)

def tour(dist):
	print(0,0)
	seen = set()
	seen.add(0)
	for i in range(n - 1):
		cur,idx = inf,None
		for j in range(n):
			if j in seen or dist[i][j] == 0:
				continue
			if dist[i][j] < cur:
				cur = dist[i][j]
				idx = j
		seen.add(idx)
		print(idx,cur)

if __name__ == "__main__":
	sys.stdin = open("input.txt", "r")	
	n = int(input()) + 1
	graph = [[inf for _ in range(n)] for _ in range(n)]
	for i in range(n):
		for j in range(n):
			if i == j:
				graph[i][j] = 0
	while True:
		try:
			u,v,w = map(int,input().split())
			graph[v][u] = w
			graph[u][v] = w
		except EOFError:
			break
	floydWarshall(graph)