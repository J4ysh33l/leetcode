// Last updated: 05/01/2026, 23:31:07
1class Solution {
2    public long maxMatrixSum(int[][] matrix) {
3        int minAbs = Integer.MAX_VALUE;
4        long sum =0;
5        int minC=0;
6        for(int i=0;i<matrix.length;i++){
7            for(int j=0;j<matrix[0].length;j++){
8                sum+=Math.abs(matrix[i][j]);
9                if(matrix[i][j]<0){
10                    minC++;
11                }
12                minAbs = Math.min(minAbs, Math.abs(matrix[i][j]));
13            }
14        }
15        if(minC%2==0){
16            return sum;
17        }else{
18            return sum-2*minAbs;
19        }
20    }
21}