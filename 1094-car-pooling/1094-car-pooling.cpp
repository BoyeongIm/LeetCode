class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trip.begin(), trips.end());
        vector<int> locations(1001);

        for (auto t : trips) {
            int passengers = t[0];
            int dep = t[1];
            int arr = t[2];
            locations[dep] += passengers;
            locations[arr] -= passengers;
        }

        int now = 0;
        for (auto p :locations) {
            now += p;
            if (now > capacity) return false;
        }
        return true;
    }
};