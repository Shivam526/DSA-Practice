class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        if(arr.size()==1) return 1;
        
        sort(arr.begin(), arr.end());
        int cnt=0;
       int ans=INT_MIN;
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i+1]==arr[i]+1) {
                cnt++;
                ans=max(ans,cnt);
            }
            
            if(arr[i+1]!=arr[i]+1 && arr[i+1]!=arr[i]) cnt=0;
        }
        
       if(ans==INT_MIN) return 1;
       return ans+1;
    }
};
