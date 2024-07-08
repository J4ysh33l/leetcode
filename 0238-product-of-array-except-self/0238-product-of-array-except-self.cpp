class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
    std::vector<int> answer(n, 1);

    // Fill the answer array with the product of elements to the left
    int leftProduct = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = leftProduct;
        leftProduct *= nums[i];
    }

    // Update the answer array with the product of elements to the right
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return answer;
    }
};