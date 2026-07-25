class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> temp1;
        vector<int> temp2;
        int k=0;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0){
                temp1.push_back(nums[i]);
            }
            else{
                temp2.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(i==0 || i%2==0){
                nums[i]=temp2[k];
                k++;

            }
            else{
                nums[i]=temp1[j];
                j++;
            }
        }
        return nums;
        
    }
};
