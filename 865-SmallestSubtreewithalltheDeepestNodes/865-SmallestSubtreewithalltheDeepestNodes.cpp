// Last updated: 09/01/2026, 14:38:48
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    
15    int action(TreeNode* root,int &maxDepth, TreeNode* &ans, int depth){
16        if(root==nullptr){
17            return depth;
18        }
19        int leftDepth= action(root->left,maxDepth,ans,depth+1);
20        int rightDepth= action(root->right,maxDepth,ans,depth+1);
21        int levelDepth = max(leftDepth,rightDepth);
22        if(rightDepth==leftDepth && maxDepth<=levelDepth){
23            ans=root;
24            maxDepth=levelDepth;
25        }
26        return levelDepth;
27    }
28
29    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
30        int maxDepth=INT_MIN;
31        TreeNode* ans=nullptr;
32        action(root,maxDepth,ans,0);
33        return ans;
34    }
35};