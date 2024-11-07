class MyCalendarTwo(object):
    def __init__(self):
        self.single = []
        self.double = []

    def book(self, startTime, endTime):
        schedule = (startTime, endTime)
        for p in self.double:
            if (startTime < p[1] and endTime > p[0]):
                return False
        for p in self.single:
            if (startTime < p[1] and endTime > p[0]):
                self.double.append((max(startTime, p[0]), min(endTime, p[1])))     
                return True 
        self.single.append(schedule)
        return True