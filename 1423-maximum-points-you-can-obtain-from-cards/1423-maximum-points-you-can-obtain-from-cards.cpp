class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum=0;
        int maxSum=0;
        for(int i=0;i<k;i++){
            totalSum+= cardPoints[i];
        }
        maxSum=totalSum;
        for(int i=0;i<k;i++){
            totalSum-=cardPoints[k-1-i];
            totalSum+= cardPoints[cardPoints.size()-i-1];
            maxSum=max(totalSum,maxSum);
        }
        return maxSum;
    }
};