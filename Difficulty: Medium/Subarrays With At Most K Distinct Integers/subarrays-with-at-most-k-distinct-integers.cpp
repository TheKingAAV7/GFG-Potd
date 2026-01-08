class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        map<int,int>mp;
        int l=0;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(mp.size()>k){
                
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            ans+=(i-l+1);
        }
        return ans;
    }
};