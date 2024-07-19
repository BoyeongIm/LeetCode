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
    bool possibleBST(TreeNode* curr, long long maxi, long long mini) {
        if (curr == nullptr) return true;
        if (curr->val < maxi && curr->val > mini) {
            return possibleBST(curr->left, curr->val, mini) && possibleBST(curr->right, maxi, curr->val);
        }

        else return false;
    }
    
    bool isValidBST(TreeNode* root) {
        long long maxi = LLONG_MAX;
        long long mini = LLONG_MIN;

        return possibleBST(root, maxi, mini);
    }
};