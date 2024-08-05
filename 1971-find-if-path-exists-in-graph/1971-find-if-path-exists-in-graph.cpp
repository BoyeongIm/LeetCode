class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, int& node, int& destination, vector<bool>& visited) {
        if (node==destination) return true;
        if (visited[node]==0) {
            visited[node]=1;
            for (auto neighbor : graph[node]) {
                if (dfs(graph, neighbor, destination, visited)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (edges.size()==0) return true;
        unordered_map<int, vector<int>> graph;
        for (auto& e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, 0);
        return dfs(graph, source, destination, visited);
    }
};