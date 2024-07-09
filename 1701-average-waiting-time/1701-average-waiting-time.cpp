class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        vector<int> currTime(n);
        vector<int> wait(n);
        currTime[0]=customers[0][1]+customers[0][0];
        wait[0]=customers[0][1];
        for(int i=1;i<customers.size();i++){
            currTime[i]=max(currTime[i-1],customers[i][0])+customers[i][1];
            wait[i]=currTime[i]-customers[i][0];
        }
        double sum=0;
        for(int i=0;i<wait.size();i++){
            sum+=wait[i];
        }
        return (sum/wait.size());
    }
};