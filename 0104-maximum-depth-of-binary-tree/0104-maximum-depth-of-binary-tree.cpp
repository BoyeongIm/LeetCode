/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        //if (!root->left && !root->right) return 1;
        
        int depth = 0;
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        while (!nodeQ.empty()) {
            depth++;
            for (int i=0; i<nodeQ.size(); i++) {
                TreeNode* curr = nodeQ.front();
                nodeQ.pop();
                if (curr->left) nodeQ.push(curr->left);
                if (curr->right) nodeQ.push(curr->right);
            }
        }

        return depth;
    }
};