# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        curr1 = headA
        curr2 = headB
        l1 = []
        l2 = []
        while curr1:   
            l1.append(curr1)
            curr1 = curr1.next
        while curr2:
            l2.append(curr2)
            curr2 = curr2.next
        for i in range(len(l1)):
            for j in range(len(l2)):
                if l1[i]==l2[j]:
                    return l1[i]
        
        return None