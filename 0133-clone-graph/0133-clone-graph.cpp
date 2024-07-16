/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* n, unordered_map<Node*, Node*>& graph) {
        Node* copied_n = new Node(n->val);
        vector<Node*> copied_neighbors;
        graph[n] = copied_n;
        for (auto nei : n->neighbors) {
            if (graph.find(nei) != graph.end()) {
                copied_neighbors.push_back(graph[nei]);
            } else {
                // Node* nb = new Node(nei->val);
                copied_neighbors.push_back(dfs(nei, graph));
            }
        }

        copied_n->neighbors = copied_neighbors;
        return copied_n;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (node->neighbors.size()==0) {
            Node* copied = new Node(node->val);
            return copied;
        }

        unordered_map<Node*, Node*> ans;
        return dfs(node, ans);
    }
};