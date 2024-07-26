class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (k==0) {
            for (const auto& e : flights) {
                if (e[0]==src && e[1]==dst) return e[2];
            }
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int, int>>> prQ;
        prQ.push({0, src, 0}); // cost, node, stops
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX)); // distance & stop
        dist[src][0] = 0;
        
        while (!prQ.empty()) {
            auto [cost, node, stops] = prQ.top();
            prQ.pop();

            if (stops > k) continue;
            
            for (const auto& e : flights) {
                if (e[0]==node) {
                    int to = e[1];
                    int w = e[2];
                    if (dist[node][stops] + w < dist[to][stops+1]) {
                        dist[to][stops+1] = cost + w;
                        prQ.push({cost+w, to, stops+1});                        
                    }                    
                }
            }
        }
        int result = INT_MAX;
        for (int i=0; i<=k+1; i++) {
            result = min(result, dist[dst][i]);
        }
        
        if (result < INT_MAX) return result;
        else return -1;
    }
};