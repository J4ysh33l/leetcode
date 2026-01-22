// Last updated: 22/01/2026, 22:40:57
1class Solution {
2public:
3
4    bool isSorted(vector<int>& nums){
5        for(int i=1;i<nums.size();i++){
6            if(nums[i]<nums[i-1]){
7                return false;
8            }
9        }
10        return true;
11    }
12
13    int solve(vector<int>& nums, int ops){
14        if(isSorted(nums)){
15        return ops;
16       } 
17       pair<int,int> minPair;
18        minPair.first=INT_MAX;
19       for(int i=0;i<nums.size()-1;i++){
20            int minSum = nums[i]+nums[i+1];
21            if(minPair.first>minSum){
22                minPair.first=minSum;
23                minPair.second=i;
24            }
25            cout<<nums[i]<<" ";
26       }
27       cout<<nums[nums.size()-1]<<" "<<endl;
28       nums[minPair.second]=minPair.first;
29       nums.erase(nums.begin()+minPair.second+1);
30       return solve(nums,ops+1);
31    }
32
33    int minimumPairRemoval(vector<int>& nums) {
34       return solve(nums,0);
35    }
36};