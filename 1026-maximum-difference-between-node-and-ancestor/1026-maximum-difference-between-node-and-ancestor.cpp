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

        int maxValue = max(maxV, root->val);
        int minValue = min(minV, root->val);

        int ans1 = maxAncestorDiff(root->left, maxValue, minValue);
        int ans2 = maxAncestorDiff(root->right, maxValue, minValue);

        return max(ans1, ans2);
    }
};