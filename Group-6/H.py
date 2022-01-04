'''
Time Complexity: O(n), where n is the number of elements in the linked list.
Space Complexity: O(1) no extra space used.
Approach:
    1. Split the linked list into two halves.
    2. Reverse the second half of the linked list.
    3. Interleave the first and second half of the linked list.

Note: To test this against other inputs use input.txt or comment line 66 to test on OJ
'''

import sys

class LLNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

def linkedlist(nums):
    head = LLNode(nums[0])
    cur = head
    for i in range(1,len(nums)):
        cur.next = LLNode(nums[i])
        cur = cur.next
    return head

def split(head):
    tail1 = tail2 = head
    while tail1 and tail2 and tail2.next and tail2.next.next:
        tail1 = tail1.next
        tail2 = tail2.next.next
    head2 = tail1.next
    tail1.next = None
    return head, head2

def reverse(head):
    if not head or not head.next:
        return head
    prev, cur = None, head
    while cur:
        nxt = cur.next
        cur.next = prev
        prev = cur
        cur = nxt
    return prev

def interleave(head1, head2):
    resHead = res = LLNode(0)
    while head1 or head2:
        if head1:
            res.next = head1
            res = res.next
            head1 = head1.next
        if head2:
            res.next = head2
            res = res.next
            head2 = head2.next
    return resHead.next

def solve(head):
    head1, head2 = split(head)
    head2 = reverse(head2)
    return interleave(head1, head2)

if __name__ == '__main__':
    sys.stdin = open('input.txt', 'r')
    n = int(input())
    head = linkedlist(list(map(int,input().split())))
    res = solve(head)
    while res:
        print(res.val,end=' ')
        res = res.next