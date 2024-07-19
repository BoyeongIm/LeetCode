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
    void DFTinorder(TreeNode* curr, vector<int>& BST) {        
        if (!curr) return;
        DFTinorder(curr->left, BST);
        BST.push_back(curr->val);
        DFTinorder(curr->right, BST);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> to_vec;
        DFTinorder(root, to_vec);
        return to_vec[k-1];
    }
};