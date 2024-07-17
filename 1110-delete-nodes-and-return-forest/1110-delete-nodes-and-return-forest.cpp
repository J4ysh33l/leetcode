class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        root = dfs(root, to_delete_set, result);
        
        if (root) {
            result.push_back(root);
        }
        
        return result;
    }

private:
    TreeNode* dfs(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& result) {
        if (!node) return nullptr;
        
        node->left = dfs(node->left, to_delete_set, result);
        node->right = dfs(node->right, to_delete_set, result);
        
        if (to_delete_set.count(node->val)) {
            if (node->left) result.push_back(node->left);
            if (node->right) result.push_back(node->right);
            return nullptr;
        }
        
        return node;
    }
};