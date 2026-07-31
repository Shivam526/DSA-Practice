class Solution {
public:

    int merge(vector<int>& nums, int low, int mid, int high) {

        int cnt = 0;
        int right = mid + 1;

        // Count reverse pairs
        for (int left = low; left <= mid; left++) {
            while (right <= high &&
                   (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }

            cnt += (right - (mid + 1));
        }

        // Merge step
        vector<int> temp;

        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        int leftCnt = mergeSort(nums, low, mid);
        int rightCnt = mergeSort(nums, mid + 1, high);
        int mergeCnt = merge(nums, low, mid, high);

        return leftCnt + rightCnt + mergeCnt;
    }

    int reversePairs(vector<int>& nums) {

        return mergeSort(nums, 0, nums.size() - 1);
    }
};
