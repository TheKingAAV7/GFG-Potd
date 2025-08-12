class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
       sort(prices.begin(),prices.end());
       int n=prices.size();
       //  1 2 3 4
       int cnt= ceil((1.0*n)/(1.0*(k+1)));
       //  
       int ans1=0;
       int ans2=0;
        for(int i=0;i<cnt;i++){
        ans1+=prices[i];
        ans2+=prices[n-i-1];
        }
        return {ans1,ans2};
        
       
        
    }
};