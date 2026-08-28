class Solution {
public:
    bool canSplit(vector<int> &nums, int k, long long limit){
        int cnt=1;
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > limit)
            return false;
            sum+=nums[i];
            if(sum>limit){
                cnt++;
                sum=nums[i];
            }
        }
        if(cnt<=k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=nums[0];
        long long high=accumulate(nums.begin(),nums.end(),0);
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(canSplit(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }

            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
