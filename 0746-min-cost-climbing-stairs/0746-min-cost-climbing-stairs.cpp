class Solution {
public:
    int solve(vector<int> cost, int* arr,int n){
        if(n==0||n==1){
            return cost[n];
        }
        if(arr[n]==-1){
            if(n<=cost.size()-1){
                arr[n]= min(solve(cost,arr,n-1),solve(cost,arr,n-2))+cost[n];
            }else{
                arr[n]= min(solve(cost,arr,n-1),solve(cost,arr,n-2));
            }
            cout<<arr[n]<<endl;
        }
        return arr[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int arr[cost.size()+1];
        fill(arr,arr+cost.size()+1,-1);
        int ans = solve(cost,arr,cost.size());
        return ans;
    }
};