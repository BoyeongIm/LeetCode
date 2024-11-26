class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        # 출발지 기준 우선 정렬 -> 도착지 기준 정렬 (오름차순)
        trips.sort(key=lambda x : (x[1], x[2]))
        # 각 인덱스에 해당하는 location일 때 몇명이 타고 몇명이 내리는지를 저장 !!!!
        count = [0] * 1001

        for people, dep, arr in trips:
            count[dep] += people # dep에서 타는 인원 저장
            count[arr] -= people # arr에서 내리는 인원 반영

        now = 0 # 각 location을 돌면서 실시간 인원 조사
        for i in range(len(count)):
            now += count[i]
            if now > capacity: # 실시간 인원이 capacity를 넘어가는 순간 False 반환
                return False
        return True