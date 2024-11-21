# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        prev = head
        curr = head.next
        nextt = head.next.next
        critical_points = []
        index = 1

        while nextt:
            if (prev.val < curr.val and curr.val > nextt.val) or (prev.val > curr.val and curr.val < nextt.val):
                critical_points.append(index)
            prev = curr
            curr = nextt
            nextt = nextt.next
            index += 1

        if len(critical_points) < 2:
            return [-1,-1]
        print(critical_points)
        min_distance = float('inf')
        max_distance = critical_points[-1] - critical_points[0]
        for i in range(len(critical_points)-1):
            for j in range(i+1, len(critical_points)):
                distance = critical_points[j]-critical_points[i]
                if distance < min_distance:
                    min_distance = distance 
        return [min_distance, max_distance]