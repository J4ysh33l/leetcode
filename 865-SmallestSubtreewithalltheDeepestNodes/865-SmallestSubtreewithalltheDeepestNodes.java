// Last updated: 09/01/2026, 14:44:58
1/**
2 * Definition for a binary tree node.
3 * public class TreeNode {
4 *     int val;
5 *     TreeNode left;
6 *     TreeNode right;
7 *     TreeNode() {}
8 *     TreeNode(int val) { this.val = val; }
9 *     TreeNode(int val, TreeNode left, TreeNode right) {
10 *         this.val = val;
11 *         this.left = left;
12 *         this.right = right;
13 *     }
14 * }
15 */
16class Solution {
17    TreeNode ans;
18    int maxDepth=Integer.MIN_VALUE;
19
20    int action(TreeNode root,int depth){
21        if(root==null){
22            return depth;
23        }
24        int leftDepth= action(root.left,depth+1);
25        int rightDepth= action(root.right,depth+1);
26        int levelDepth = Math.max(leftDepth,rightDepth);
27        if(leftDepth==rightDepth && maxDepth<=levelDepth){
28            maxDepth=levelDepth;
29            ans=root;
30        }
31        return levelDepth;
32    }
33
34    public TreeNode subtreeWithAllDeepest(TreeNode root) {
35        
36        action(root,0);
37        return ans;
38    }
39}