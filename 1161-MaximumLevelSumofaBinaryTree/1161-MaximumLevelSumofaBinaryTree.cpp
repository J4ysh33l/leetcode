// Last updated: 06/01/2026, 10:02:07
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
14    int maxLevelSum(TreeNode* root) {
15
16        if(root==nullptr){
17            return 0;
18        }
19        int minLevel=0;
20        int maxLevelSum=INT_MIN;
21        int level=1;
22        queue<TreeNode*> q;
23        q.push(root);
24        while(!q.empty()){
25            int levelSum=0;
26            int sizeQ= q.size();
27            for(int i=0;i<sizeQ;i++){
28                TreeNode* act = q.front();
29                levelSum+=act->val;
30
31                if(act->left){
32                    q.push(act->left);
33                }
34                if(act->right){
35                    q.push(act->right);
36                }
37                q.pop();
38            }
39            if(maxLevelSum<levelSum){
40                minLevel=level;
41                maxLevelSum=levelSum;
42            }
43            level++;
44        }
45        return minLevel;
46    }
47};