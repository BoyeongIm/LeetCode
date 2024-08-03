# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head.next:
            return True
        
        linkedstack = []
        curr = head
        while curr:
            linkedstack.append(curr.val)
            curr = curr.next

        while linkedstack:
            v = linkedstack.pop()
            if head.val == v:
                head = head.next
            else:
                return False

        return True