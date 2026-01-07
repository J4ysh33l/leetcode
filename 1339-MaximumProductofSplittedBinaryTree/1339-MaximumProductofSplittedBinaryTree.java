// Last updated: 07/01/2026, 21:22:09
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
17
18    long maxProd=0;
19    public long TreeSum(TreeNode root){
20        if(root==null){
21            return 0;
22        }
23
24        return TreeSum(root.left) + root.val + TreeSum(root.right);
25    }
26
27    public long ans(TreeNode root, long treeSum){
28        if(root==null){
29            return 0;
30        }
31
32        long leftTreeSum = ans(root.left,treeSum)+root.val+ans(root.right,treeSum);
33        long rightTreeSum = treeSum-leftTreeSum;
34
35        long newProd= leftTreeSum*rightTreeSum;
36        maxProd= Math.max(maxProd,newProd);
37        return leftTreeSum;
38
39    }
40
41    public int maxProduct(TreeNode root) {
42        long treeSum = TreeSum(root);
43        ans(root,treeSum);
44        return (int) (maxProd % 1000000007);
45    }
46}