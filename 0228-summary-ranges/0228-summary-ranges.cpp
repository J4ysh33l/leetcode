class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> str;
        bool range = false;
        string start;
        for(int i = 0; i < nums.size(); i++) {
            if(i < nums.size() - 1 && nums[i] + 1 == nums[i + 1]) {
                if(!range) {
                    start = to_string(nums[i]); 
                }
                range = true;
            } else {
                if(range) {
                    str.push_back(start + "->" + to_string(nums[i])); 
                } else {
                    str.push_back(to_string(nums[i])); 
                }
                range = false;
            }
        }
        return str; 
    }
};
