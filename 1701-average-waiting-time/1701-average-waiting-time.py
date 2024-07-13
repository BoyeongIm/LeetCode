class Solution(object):
    def averageWaitingTime(self, customers):
        """
        :type customers: List[List[int]]
        :rtype: float
        """
        total_waiting_time = customers[0][1]
        finish = sum(customers[0])
        for arrival, preparing in customers[1:]:
            if finish <= arrival: # 셰프가 기다림
                finish = arrival+preparing # 새로운 손님의 도착시간+준비시간으로 초기화
                total_waiting_time += preparing
            else: # 손님이 기다림
                finish += preparing # 이 손님꺼의 준비시간만큼 더함
                total_waiting_time += finish-arrival

        return float(total_waiting_time)/len(customers)