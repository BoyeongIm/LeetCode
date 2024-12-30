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
    int dfs(TreeNode* currNode, int maxval, int minval) {
        if (currNode == nullptr) return maxval-minval;
        maxval = max(currNode->val, maxval);
        minval = min(currNode->val, minval);

        int left_diff = dfs(currNode->left, maxval, minval);
        int right_diff = dfs(currNode->right, maxval, minval);

        return left_diff > right_diff ? left_diff : right_diff;
    }

    int maxAncestorDiff(TreeNode* root) {
        int l = dfs(root->left, root->val, root->val);
        int r = dfs(root->right, root->val, root->val);

        return l > r ? l : r;
    }
};