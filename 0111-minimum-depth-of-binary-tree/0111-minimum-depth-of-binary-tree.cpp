class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int n = q.size();
            for (int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                if (!curr->left && !curr->right) return depth;
                }
            }

        return depth;
    }
};