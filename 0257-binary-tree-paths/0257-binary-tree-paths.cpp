class Solution {
public:
    void dfs(TreeNode*& currNode, vector<string>& paths, string path) {
        if (!currNode->left && !currNode->right) {
            if (find(paths.begin(), paths.end(), path) == paths.end()) {
                paths.push_back(path);
            }
        }

        if (currNode->left) dfs(currNode->left, paths, path+"->"+to_string(currNode->left->val));
        if (currNode->right) dfs(currNode->right, paths, path+"->"+to_string(currNode->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> paths;
        dfs(root, paths, to_string(root->val));
        return paths;
    }
};