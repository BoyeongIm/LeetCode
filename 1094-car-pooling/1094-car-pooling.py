class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort(key=lambda x : (x[1], x[2]))
        count = [0] * 1001
        for i in range(len(trips)):
            people = trips[i][0]
            dep = trips[i][1]
            arr = trips[i][2]
            count[dep] += people
            count[arr] -= people
        now = 0
        for i in range(len(count)):
            now += count[i]
            if now > capacity:
                return False
        return True