class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> prefix_sum;
        
        // Base case: prefix sum of 0 has occurred 1 time (before starting the array)
        prefix_sum[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int preSum = sum - k;

            // 1. If (sum - k) exists in map, add its frequency to total count
            if (prefix_sum.find(preSum) != prefix_sum.end()) {
                cnt += prefix_sum[preSum];
            }

            // 2. Record/increment frequency of current prefix sum
            prefix_sum[sum]++;
        }

        return cnt;
    }
};
