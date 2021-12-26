'''
Time Complexity: O((n+m)//2) we are iterating through the half of the implicitly combined array
Space Complexity: O(max(n,m)) space used for the input arrays
Approach:
	1. Find the midpoint implicit combined array: (n+m)//2
	2. Iterate through the arrays always picking the minimum of the two arrays using two-pointer
Note: To test this against other inputs use input.txt or comment line 22 to test on OJ
'''

import sys

def findMedian(pileA,pileB):
	i,j,m = 0,0,(len(pileA) + len(pileB)) // 2
	for _ in range(m):
		if pileA[i] < pileB[j]:
			i += 1
		else:
			j += 1
	return min(pileA[i],pileB[j])

if __name__ == "__main__":
	sys.stdin = open("input.txt", "r")
	n = int(input())
	pileA = list(map(int,input().split()))
	m = int(input())
	pileB = list(map(int,input().split()))
	print(findMedian(pileA,pileB))