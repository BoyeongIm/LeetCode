class Solution(object):
    def getIntersectionNode(self, headA, headB):
        curr1, curr2 = headA, headB
        alength, blength = 0, 0

        while curr1:
            alength+=1
            curr1 = curr1.next
        while curr2:
            blength+=1
            curr2 = curr2.next
        
        currA = headA
        currB = headB
        if alength > blength:
            for i in range(alength-blength):
                currA = currA.next
        else:
            for i in range(blength-alength):
                currB = currB.next

        while currA!=currB:
            currA = currA.next
            currB = currB.next
            
        return currA