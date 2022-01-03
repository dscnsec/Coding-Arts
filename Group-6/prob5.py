'''
Time Complexity: O(x*n), where x is the number of queries and n is the number of users. 
Space Complexity: O(n^2), where n is the number of users. Space used to store the followers graph.
In the worst case of complete graph where all the users are connected to all other nodes, esp. the querier.
Approach:
    1. Build a graph from the given edge list
    2. For each query, find the users that are connected to D and C is not connected to those users.
Note: To test this against other inputs use input.txt or comment line 22 to test on OJ
'''

import sys
from collections import defaultdict

def suggestionQuerier(userC,userD):
    suggestions = [user for user in followers[userD] if userC not in followers[user]]
    if not suggestions: print(0)
    else:
        for suggestion in suggestions: print(suggestion, end=' ')
        print()

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    n,m = map(int,input().split())
    followers = defaultdict(list)
    for _ in range(m):
        userA,userB = input().split()
        followers[userB].append(userA)
    x = int(input())
    for _ in range(x):
        userC,userD = input().split()
        suggestionQuerier(userC, userD)
