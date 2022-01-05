'''
Time Complexity: O(n+m), where n is the number of students in the first group and m is the number of students in the second group.
Space Complexity: O(1), no extra space used.
Approach:
    keeping this as a reference: 
    "It is always true that there will always be only one student whose height will match with no one."
    1. Find the student whose height is not matched with anyone in the first group 
    by XORing all the heights of the first group.
    2. Find the student whose height is not matched with anyone in the second group 
    by taking mod 3 of the bitwise sum of heights

Note: To test this against other inputs use input.txt or comment line 38 to test on OJ
'''

import sys
from functools import reduce
from operator import xor

def duoElimination(duos,n):
    return reduce(xor,duos)

def trioElimination(trios,m):
    INT_LEN = 32
    result = 0
    for i in range(INT_LEN):
        curSum = 0
        x = 1<<i
        for student in trios:
            if student & x: curSum += 1
        if curSum % 3: result |= x
    return result


def solve(duos, trios, n, m):
    return [duoElimination(duos, n), trioElimination(trios, m)]

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    n = int(input())
    duos = list(map(int,input().split()))
    m = int(input())
    trios = list(map(int,input().split()))
    eliminated = solve(duos, trios, n, m)
    for student in eliminated:
        print(student, end=' ')