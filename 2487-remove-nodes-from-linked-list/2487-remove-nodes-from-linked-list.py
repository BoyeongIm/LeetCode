# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNodes(self, head):
        if not head.next:
            return head

        tolist = []
        curr = head
        while curr:
            tolist.append(curr)
            curr = curr.next
        tolist.reverse()
        maxnode = tolist[0]
        for i in range(1, len(tolist)):
            if tolist[i].val >= maxnode.val:
                tolist[i].next = maxnode
                maxnode = tolist[i]
            else:
                head = maxnode

        return head
        