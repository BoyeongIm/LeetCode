class ExamRoom(object):
    def __init__(self, n):
        self.size = n
        self.seated = []

    def seat(self):
        if not self.seated:
            self.seated.append(0)
            return 0

        seat = 0
        self.seated.sort()
        max_distance = -1
        
        for i in range(len(self.seated)-1):
            currdist = (self.seated[i+1]-self.seated[i])//2
            if currdist > max_distance:
                max_distance = currdist
                seat = self.seated[i] + currdist

        if max_distance < self.size-1 - self.seated[-1]:
            seat = self.size-1

        self.seated.append(seat)
        return seat

    def leave(self, p):
        if p in self.seated:
            self.seated.remove(p)

# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)