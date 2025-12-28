class Solution {
  public:
    int minTime(vector<int>& ranks, int n) {
        // code here
        int m=ranks.size();
        int ans=0;
        int cnt=0;
        
        int lo=0;
        int hi=1e9;
        
      auto donuts_for_rank = [&](long long mid, int a)->long long{
    long long T = (2LL * mid) / a;                      // k(k+1) <= T
    long long k = (long long)((-1.0 + sqrt(1.0 + 4.0*T)) / 2.0);
    if(k < 0) k = 0;
    return k;
};

auto f = [&](long long mid)->bool{
    long long donuts = 0;
    for(int a : ranks){
        donuts += donuts_for_rank(mid, a);
        if(donuts >= n) return true;
    }
    return donuts >= n;
};
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
       
        return ans;
        
    }
};