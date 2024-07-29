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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* temp1 = root;
        TreeNode* temp2 = root;
        
        for (int i=mid-1; i>=0; i--) {
            TreeNode* node = new TreeNode(nums[i]);
            temp1->left = node;
            temp1 = node;
        }

        for (int j=mid+1; j<nums.size(); j++) {
            TreeNode* node = new TreeNode(nums[j]);
            temp2->right = node;
            temp2 = node;
        }

        return root;
    }
};