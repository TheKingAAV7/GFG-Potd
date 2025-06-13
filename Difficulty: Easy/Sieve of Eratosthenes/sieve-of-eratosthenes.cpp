// User function Template for C++
class Solution {
  public:
    vector<int> sieveOfEratosthenes(int n) {
        vector<int>prime(n+1,1);
        for(int p=2;p*p<=n;p++){
            if(prime[p]){
                for(int i=p*p;i<=n;i+=p){
                    prime[i]=0;
                }
            }
        }
        vector<int>ans;
        for(int i=2;i<=n;i++) {
            if(prime[i]) ans.push_back(i);
        }
        return ans;
        
    }
};