class Solution {
public:
    vector<string> dfs(TreeNode*& currNode, vector<string>& paths, string path) {
        if (!currNode->left && !currNode->right) {
            if (find(paths.begin(), paths.end(), path) == paths.end()) {
                paths.push_back(path);
            }
            return paths;
        }

        if (currNode->left) {
            paths = dfs(currNode->left, paths, path+"->"+to_string(currNode->left->val));
        }
        if (currNode->right) {
            paths = dfs(currNode->right, paths, path+"->"+to_string(currNode->right->val));
        }

        return paths;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> paths;
        paths = dfs(root, paths, to_string(root->val));
        return paths;
    }
};