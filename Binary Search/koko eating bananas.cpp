class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        int ans=0;
        for(int i=0; i<piles.size(); i++){
            high=max(piles[i],high);
        }
        
        while(low<=high){
             long long total_hours=0;
            int mid=low+(high-low)/2;
             
             for(int i=0; i<piles.size(); i++){
                if(mid>=piles[i]){
                    total_hours+=1;
                }
                else{
                   total_hours += (piles[i] + mid - 1) / mid;
                }
             }

             if(total_hours<=h){
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
