class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_waiting_time = 0.0;
        int finish = 0;
        for (const auto& c : customers) {
            int arrival = c[0];
            int preparing = c[1];
            if (finish <= arrival) { // 셰프가 기다림
                finish = arrival+preparing; // 새로운 손님의 도착시간+준비시간으로 초기화
                total_waiting_time += preparing;
            }
            else { // 손님이 기다림
                finish += preparing; // 이 손님꺼의 준비시간만큼 더함
                total_waiting_time += finish-arrival;
            }
        }

        return total_waiting_time/customers.size();
    }
};