class Solution(object):
    def getIntersectionNode(self, headA, headB):
        curr1 = headA
        curr2 = headB
        alength = 0
        blength = 0
        while curr1:
            alength+=1
            curr1 = curr1.next
        while curr2:
            blength+=1
            curr2 = curr2.next
        
        currA = headA
        currB = headB
        if alength > blength:
            n = alength-blength
            for i in range(n):
                currA = currA.next
            while currA!=currB and (currA.next and currB.next):
                currA = currA.next
                currB = currB.next
        else:
            n = blength-alength
            for i in range(n):
                currB = currB.next
            while currA!=currB and (currA.next and currB.next):
                currA = currA.next
                currB = currB.next
        
        if currA==currB:
            return currA
        else:
            return None