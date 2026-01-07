// Last updated: 07/01/2026, 21:03:25
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
18        int leftVal=ansTree(root->left,maxProd,totalSum),rightVal=ansTree(root->right,maxProd,totalSum);
19        long long leftSum = leftVal+rightVal+root->val;
20        long long rightSum = totalSum-leftSum;
21        long long newProd = leftSum*rightSum;
22        maxProd = max(maxProd, newProd);
23        return leftSum;
24    }
25
26    int treeSum(TreeNode* root){
27        if(root==nullptr){
28            return 0;
29        }
30        int leftSum=treeSum(root->left),rightSum=treeSum(root->right);
31        return leftSum+rightSum+root->val;
32    }
33
34    int maxProduct(TreeNode* root) {
35        long long maxProd = INT_MIN;
36        int totalSum=treeSum(root);
37        ansTree(root,maxProd,totalSum);
38        return maxProd % 1000000007;
39    }
40};