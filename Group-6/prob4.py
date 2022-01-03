'''
Time Complexity: O(n), where n is the number of nodes. 
In the worst case of skewed tree we iterate through the tree only by a constant factor.
Space Complexity: O(1), without considering the space used to store the tree (C * n) and the space used by the recursion stack (n). 
Approach:
    1. Build the tree from the given level order traversal.
    2. Find the lowest common ancestor of n and m.
    3. Count the number of turns from lca to n and m.
Note: To test this against other inputs use input.txt or comment line 76 to test on OJ
'''

import sys
from math import inf

class Tree():
    def __init__(self,val,left=None,right=None):
        self.val = val
        self.left = left
        self.right = right

def build(nums):
    que = []
    cur = nums.pop(0)
    root = Tree(int(cur))
    que.append(root)
    while que and len(nums) > 1:
        node = que.pop(0)
        curl,curr = nums.pop(0),nums.pop(0)
        if curl != 'N':
            node.left = Tree(int(curl))
            que.append(node.left)
        if curr != 'N':
            node.right = Tree(int(curr))
            que.append(node.right)
    return root

def lca(root,n,m):
    if root is None: return root
    if root.val == n or root.val == m: return root
    l,r = lca(root.left,n,m),lca(root.right,n,m)
    return root if l and r else l if l else r

def turns_count(root,val,turn):
    global count
    if root is None: return False
    if root.val == val: return True
    if turn is True:
        if turns_count(root.left, val, turn): return True
        if turns_count(root.right, val, not turn):
            count += 1
            return True
    else:
        if turns_count(root.right, val, turn): return True
        if turns_count(root.left, val, not turn):
            count += 1
            return True
    return False    

def solve(nums,n,m):
    if not nums: return -1
    root = build(nums)
    lca_node = lca(root,n,m)
    if not lca_node: return -1
    global count
    count = 0
    if lca_node.val == n or lca_node.val == m:
        turns_count(lca_node.right, n if lca_node.val != n else m, False)
        turns_count(lca_node.left, n if lca_node.val != n else m, True)
        return -1 if not count else count
    else:
        for node,dirr in ((x,y) for x in [n,m] for y in [True,False]):
            turns_count(lca_node.left if dirr else lca_node.right, node, dirr)
        return count + 1

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    nums = list(input().split())
    n,m = map(int,input().split())
    print(solve(nums,n,m))
