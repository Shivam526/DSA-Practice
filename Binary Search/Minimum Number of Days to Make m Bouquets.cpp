class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
       if(1LL * m * k > bloomDay.size()) return -1;
        int low=1;
        int high=INT_MIN;
       int ans=0;
        for(int i=0; i<bloomDay.size(); i++){
            high=max(high,bloomDay[i]);
        }

        while(low<=high){
             
            int mid=low+(high-low)/2;
            int adjacent=0;
            int bouq=0;
            for(int i=0; i<bloomDay.size(); i++){
                if(bloomDay[i]<=mid){
                    adjacent+=1;
                    if(adjacent==k){
                        bouq+=1;
                        adjacent=0;
                    }
                }
                else{
                    adjacent=0;
                    
                }
            }
            if(bouq>=m){
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
