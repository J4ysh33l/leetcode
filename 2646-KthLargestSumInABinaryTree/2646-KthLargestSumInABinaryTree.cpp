// Last updated: 05/01/2026, 00:04:20
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        if(root==nullptr){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long levelSum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();
                levelSum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            // cout<<levelSum<<endl;
            sum.push_back(levelSum);
        }   

        sort(sum.begin(),sum.end());
        if (k <= sum.size()) {
            return sum[sum.size()-k]; 
        }
        return -1;
    }
};