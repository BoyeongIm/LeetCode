# Definition for singly-linked list.
#class ListNode(object):
#    def __init__(self, val=0, next=None):
#        self.val = val
#        self.next = next
class Solution(object):
    def middleNode(self, head):
        length = 0
        tofindl = head
        while (tofindl):
            length += 1
            tofindl = tofindl.next
        idx = length // 2
        while (idx>0):
            head = head.next
            idx -= 1
        return head