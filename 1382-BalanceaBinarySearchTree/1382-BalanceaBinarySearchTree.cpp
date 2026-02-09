// Last updated: 10/02/2026, 01:02:01
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
14    vector<TreeNode*> inorder;
15    void findInorder(TreeNode* root)
16    {
17        if(root==NULL)
18            return;
19        findInorder(root->left);
20        inorder.push_back(root);
21        findInorder(root->right);
22    }
23    TreeNode* buildTree(int start,int end)
24    {
25        if(start>end)
26            return NULL;
27        int mid=(start+end)/2;
28        TreeNode* root=inorder[mid];
29        root->left=buildTree(start,mid-1);
30        root->right=buildTree(mid+1,end);
31        return root;
32    }
33    TreeNode* balanceBST(TreeNode* root) 
34    {
35        if(root==NULL)
36            return NULL;
37        findInorder(root);
38        int n=inorder.size();
39        root=buildTree(0,n-1);
40        return root;
41    }
42};