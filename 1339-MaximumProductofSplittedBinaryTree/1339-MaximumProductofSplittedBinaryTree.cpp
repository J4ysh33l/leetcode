// Last updated: 07/01/2026, 21:32:06
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
14    int ansTree(TreeNode* root, long long &maxProd, int &totalSum){
15        if(root==nullptr){
16            return 0;
17        }
18        long left = ansTree(root->left,maxProd,totalSum);
19        long right = ansTree(root->right,maxProd,totalSum);
20        long long leftSum = left + right + root->val;
21        long long rightSum = totalSum-leftSum;
22        long long newProd = leftSum*rightSum;
23        maxProd = max(maxProd, newProd);
24        return leftSum;
25    }
26
27    int treeSum(TreeNode* root){
28        if(root==nullptr){
29            return 0;
30        }
31        int leftSum=treeSum(root->left),rightSum=treeSum(root->right);
32        return leftSum+rightSum+root->val;
33    }
34
35    int maxProduct(TreeNode* root) {
36        long long maxProd = INT_MIN;
37        int totalSum=treeSum(root);
38        ansTree(root,maxProd,totalSum);
39        return maxProd % 1000000007;
40    }
41};