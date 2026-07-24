class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int> Found;
        for(int i=0; i<nums.size(); i++){
            int need=target-nums[i];
            if(Found.find(need)!=Found.end()){
                
             return {i,Found[need]};
            }
            if(Found.find(need)==Found.end()){
                Found[nums[i]]=i;
            }
        } return {0};
    }
};
