class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> graph;
        for (auto& v:times) {
            graph[v[0]].push_back(make_pair(v[1],v[2]));
        }
        vector<int> dist(n+1, 10000);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> prQ;
        prQ.push(make_pair(0, k));
        dist[k] = 0;
        int min_w = INT_MAX;

        while (!prQ.empty()) {
            int total_weight = prQ.top().first;
            int u = prQ.top().second;
            prQ.pop();

            for (const auto& edge:graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u]+weight;
                    prQ.push(make_pair(dist[v],v));
                }
            }
            min_w = total_weight;
        }
        return min_w>0 ? min_w : -1;
    }
};