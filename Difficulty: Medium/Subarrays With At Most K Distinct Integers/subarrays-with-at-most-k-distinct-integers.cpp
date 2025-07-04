class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n=arr.size();
     //   int total= n*(n+1)/2;
        int cnt=0;
        int l=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(mp.size()>k){
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
            cnt+=(i-l+1);
        }
        return cnt;
        
    }
};