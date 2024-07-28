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
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int depth=1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int n = q.size();
            for (int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (!curr->left&&!curr->right) break;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        return depth;
    }
};