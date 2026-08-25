class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
             long long total=0;
             for(int i=0; i<nums.size(); i++){
                if(nums[i]%mid>0 && nums[i]>mid){
                    total+=(nums[i]/mid)+1;
                }

                else if(nums[i]<mid){
                    total+=1;
                }

                else{
                    total+=nums[i]/mid;
                }
             }

             if(total<=threshold){
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
