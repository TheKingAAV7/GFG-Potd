class Solution {
  public:
    int findPosition(int n) {
        // code here
        int ans=0;
        int cnt=0;
        for(int i=0;i<30;i++){
            if((n>>i)&1){
                cnt++;
                ans= i+1;
            }
        }
        if(cnt>1) return -1;
        return ans;    
    }
};