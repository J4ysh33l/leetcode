/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*,bool> solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return make_pair(nullptr,false);
        }
        bool current = (root==p || root==q);
        pair<TreeNode*,bool> left= solve(root->left,p,q);
        pair<TreeNode*,bool> right= solve(root->right,p,q);
        if(left.second && right.second){
            return make_pair(root,true);
        }
        if(current && (left.second || right.second)){
            return make_pair(root,true);
        }
        if (current || left.second || right.second) {
            return make_pair(current ? root : (left.first ? left.first : right.first), true);
        }

        return make_pair(nullptr,false);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<TreeNode*,bool> ans;
        ans= solve(root,p,q);
        return ans.first;
    }
};