class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int PrevSum=0;
        for(int i=0; i<nums.size(); i++){
          PrevSum+=nums[i];
          maxi=max(maxi,PrevSum);
        
          if(PrevSum<0){
            PrevSum=0;
          }
          
        }
        return maxi;
    }
};
