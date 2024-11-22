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
        int max_w = INT_MIN;

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
        }
        for (int i=1; i<=n; i++) {
            if ((i!=k) && dist[i] > max_w) max_w = dist[i];
        }
        return max_w==10000 ? -1 : max_w;
    }   
};