class Solution {
public:
    vector<string> dfs(TreeNode*& currNode, vector<string>& paths, string path) {
        if (!currNode->left && !currNode->right) {
            if (find(paths.begin(), paths.end(), path) == paths.end()) {
                paths.push_back(path);
            }
            return paths;
        }

        if (currNode->left) dfs(currNode->left, paths, path+"->"+to_string(currNode->left->val));
        if (currNode->right) dfs(currNode->right, paths, path+"->"+to_string(currNode->right->val));

        return paths;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> paths;
        return dfs(root, paths, to_string(root->val));
    }
};