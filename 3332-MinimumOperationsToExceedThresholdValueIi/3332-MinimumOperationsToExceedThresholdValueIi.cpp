// Last updated: 05/01/2026, 00:03:13
class Solution {
public:
    static int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ans=0;
        while(pq.top()<k){
            long long x=pq.top(); pq.pop();
            long long y=pq.top(); pq.pop();
            pq.push(2*x+y);
            ans++;
        }
        return ans;  
    }
};
