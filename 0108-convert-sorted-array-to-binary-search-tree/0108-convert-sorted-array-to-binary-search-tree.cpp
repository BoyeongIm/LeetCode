class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left;
        for (int i=0; i<mid; i++) {
            left.push_back(nums[i]);
        }

        vector<int> right;
        for (int j=mid+1; j<nums.size();j++) {
            right.push_back(nums[j]);
        }
        if (left.size()>0) root->left = sortedArrayToBST(left);
        if (right.size()>0) root->right = sortedArrayToBST(right);

        return root;
    }
};