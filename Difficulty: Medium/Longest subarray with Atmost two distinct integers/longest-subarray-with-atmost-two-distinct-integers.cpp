class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n=arr.size();
        int ans=1;
        int l=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
        
    }
};