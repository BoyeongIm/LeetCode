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
    int maxAncestorDiff(TreeNode* root, int maxV=INT_MIN, int minV=INT_MAX) {
        if (!root) return maxV-minV;

        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        int ans1 = maxAncestorDiff(root->left, maxV, minV);
        int ans2 = maxAncestorDiff(root->right, maxV, minV);

        return max(ans1, ans2);
    }
};