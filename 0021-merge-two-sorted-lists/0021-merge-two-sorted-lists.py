# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not list1:
            return list2
        elif not list2:
            return list1
        elif not list1 and not list2:
            return None
        
        curr1, curr2 = list1, list2
        newL = ListNode(0)
        p = newL
        while curr1 and curr2:
            if curr1.val < curr2.val:
                p.next = curr1
                curr1 = curr1.next
            else:
                p.next = curr2
                curr2 = curr2.next
            p = p.next
        if curr1:
            p.next = curr1
        else:
            p.next = curr2

        return newL.next