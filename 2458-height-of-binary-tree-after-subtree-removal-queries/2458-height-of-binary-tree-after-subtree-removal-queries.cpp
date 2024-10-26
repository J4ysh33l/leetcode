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
    int solve(TreeNode* root, int query){
        if(root==NULL || root->val==query){
            return 0;
        }
        int leftHeight= solve(root->left,query);
        int rightHeight= solve(root->right,query);

        return max(leftHeight,rightHeight)+1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans(queries.size());
        if(root==NULL){
            return ans;
        }
        for(int i=0;i<queries.size();i++){
            ans[i]=max(solve(root->left,queries[i]),solve(root->right,queries[i]));
        }
        return ans;
    }
};