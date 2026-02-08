// Last updated: 08/02/2026, 19:59:18
1class Solution {
2public:
3    bool isBalanced(TreeNode* root) {
4        return dfsHeight(root) != -1;
5    }
6
7private:
8    int dfsHeight(TreeNode* node) {
9        if (!node) return 0;
10
11        int leftHeight = dfsHeight(node->left);
12        if (leftHeight == -1) return -1;
13
14        int rightHeight = dfsHeight(node->right);
15        if (rightHeight == -1) return -1;
16
17        if (abs(leftHeight - rightHeight) > 1) return -1;
18
19        return 1 + max(leftHeight, rightHeight);
20    }
21};