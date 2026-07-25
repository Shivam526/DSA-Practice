class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;

        // Step 1: Find first decreasing element from right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // If no such element found
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find element just greater than nums[idx]
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 3: Reverse the remaining part
        reverse(nums.begin() + idx + 1, nums.end());
        
    }
};
