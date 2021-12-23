'''
Time Complexity: O(max(m,q)) where m is the number of connections and q is the number of queries
Space Complexity: O(n+m) where n is the number of people and m is the number of connections 
In the worst case (complete graph) space complexity is still n + m as m = n ^ 2 in complete graph
Approach:
	1. Create a graph of the connections
	2. Iterate through the queries
	3. Print the number of connections and the connections
Note: To test this against other inputs use input.txt or comment line 27 to test on OJ
'''

import sys
from collections import defaultdict

def followQuerier():
	while True:
		try:
			user = input()
			print(len(followers[user]))
			for i in followers[user]:
				print(i, end=' ')
			print()
		except EOFError:
			break

if __name__ == "__main__":
	sys.stdin = open("input.txt", "r")
	n,m = map(int,input().split())
	followers = defaultdict(list)
	for _ in range(m):
		userA,userB = input().split()
		followers[userB].append(userA)
	followQuerier()