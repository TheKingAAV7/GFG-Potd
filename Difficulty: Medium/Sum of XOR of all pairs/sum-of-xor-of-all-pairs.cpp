
#define ll long long
class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        /*
        
        arr[0]^arr[1] + arr[0]^arr[2] + arr[0]^arr[3]
        
        arr[1]^arr[2] + arr[1]^arr[3]
        
        
        for an element for a bit check, how many times that bit was set to the right
        
        111 + 001 = 1000
        
        110 + 111
        */
        int n= arr.size();
        ll ans=0;
        vector<int>v(31,0);
        auto f=[&](int x,int idx)->ll{
          ll sm=0;
          for(int b=0;b<30;b++){
              if((x>>b)&1){
                  int sz= n-idx-1;
                  int unset= sz-v[b];
                  sm+= 1ll* unset* (1ll<<b);
              }
              else{
                  sm+= 1ll*v[b]*(1ll<<b);
              }
          }
          return sm;
        };
        for(int i=n-1;i>=0;i--){
            ans+=f(arr[i],i);
            for(int b=0;b<30;b++){
                if((arr[i]>>b)&1) v[b]++;
            }
        }
        return ans;
        
        
        
    }
};