/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int __help(struct TreeNode* curr, int* order, int k) {
    if (curr == NULL) return -1;
    int left = __help(curr->left, order, k);
    if (left != -1) return left;
    (*order) ++;
    if (*order == k) return curr->val;
    return __help(curr->right, order, k);
}

int kthSmallest(struct TreeNode* root, int k) {
    int order = 0;
    return __help(root, &order, k);
}