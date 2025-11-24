class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        /*
        
        Just count the frequncies of the elements
        
        
        
        
        */
        
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++) {
            int left=(i+1);
            int right= (n-i);
            mp[arr[i]]+=(left*right);
        }
        int ans=0;
        for(auto it:mp){
            if(it.second%2){
                ans^=it.first;
            }
        }
        return ans;
        
    }
};