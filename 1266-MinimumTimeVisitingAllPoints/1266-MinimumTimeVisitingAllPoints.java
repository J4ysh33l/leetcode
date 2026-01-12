// Last updated: 13/01/2026, 00:22:14
1class Solution {
2    public int minTimeToVisitAllPoints(int[][] points) {
3        int travel=0;
4        for(int i=1;i<points.length;i++){
5            int x =Math.abs(points[i-1][0]-points[i][0]); 
6            int y =Math.abs(points[i-1][1]-points[i][1]);
7            travel+=Math.max(x,y);
8        }
9        return travel;
10    }
11}