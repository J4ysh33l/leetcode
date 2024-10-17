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
    bool solve(TreeNode* root, int k, int sum){
        if(root==nullptr){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL && sum==k){
            return true;
        }
        
        
        bool leftSum= solve(root->left,k,sum);
        bool rightSum= solve(root->right,k,sum);

        return (leftSum||rightSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        bool ans= solve(root,targetSum,0);
        return ans;
    }
};