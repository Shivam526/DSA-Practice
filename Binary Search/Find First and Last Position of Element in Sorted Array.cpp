class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=-1;
        int end=-1;
        int low1=0;
        int high1=nums.size()-1;
        vector<int> ans;
         while(low1<=high1){
           int mid=low1+(high1-low1)/2;
           if(nums[mid]==target) st=mid;
           if(target<=nums[mid]){
            high1=mid-1;
           }
           else{low1=mid+1; 
         }
         ans.push_back(st);
          int low2=0;
        int high2=nums.size()-1;
        while(low2<=high2){
           int mid=low2+(high2-low2)/2;
           if(nums[mid]==target) end=mid;
           if(target<nums[mid]){
            high2=mid-1;}
           else{low2=mid+1;} }
        ans.push_back(end);
   return ans;
        
    }
};
