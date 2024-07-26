class Solution {
public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 10001));
        map<int, int> threshold_freq;

        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }

        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            distance[start][end] = weight;
            distance[end][start] = weight;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][k] + distance[k][j] < distance[i][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][j] <= distanceThreshold) {
                    if (threshold_freq.find(i) != threshold_freq.end())
                        threshold_freq[i]++;
                    else
                        threshold_freq[i] = 1;
                }
            }
        }

        vector<pair<int, int>> threshold_freq2(threshold_freq.begin(),
                                               threshold_freq.end());
        sort(threshold_freq2.begin(), threshold_freq2.end(), cmp);
        return threshold_freq2.begin()->first;
    }
};