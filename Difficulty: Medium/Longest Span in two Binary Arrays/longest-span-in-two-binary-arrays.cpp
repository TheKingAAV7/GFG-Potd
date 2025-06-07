class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
       int sum1=0,sum2=0,ans=0;
       int n=arr1.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum1 += arr1[i];
            sum2 += arr2[i];
            if(sum1==sum2)
                ans = i+1;
            if(mp.find(sum1-sum2)!=mp.end())
                ans = max(ans,i-mp[sum1-sum2]);
            else
                mp[sum1-sum2] = i;
        }
        return ans;
    }
};