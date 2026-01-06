// Last updated: 06/01/2026, 18:30:48
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
17    public int maxLevelSum(TreeNode root) {
18        int level=1;
19        int minLevel=0;
20        int maxLevelSum=Integer.MIN_VALUE;
21
22        Queue<TreeNode> q= new LinkedList<TreeNode>();
23        q.add(root);
24        while(!q.isEmpty()){
25            int qSize = q.size();
26            int levelSum=0;
27            for(int i=0;i<qSize;i++){
28                TreeNode elm = q.peek();
29                levelSum+=elm.val;
30                if(elm.left!=null){
31                    q.add(elm.left);
32                }
33                if(elm.right!=null){
34                    q.add(elm.right);
35                }
36                q.remove();
37            }
38            if(maxLevelSum<levelSum){
39                minLevel=level;
40                maxLevelSum=levelSum;
41            }
42            level++;
43        }
44        return minLevel;
45    }
46}