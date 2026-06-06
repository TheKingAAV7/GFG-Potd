class Solution {
  public:
    int numOfWays(int n, int m) {
        // code here
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int total=n*m-1;
                int cnt=0;
                if(j-2>=0 and i+1<n) cnt++;
                if(j+2<m and i+1<n) cnt++;
                if(j-1>=0 and i+2<n) cnt++;
                if(j+1<m and i+2<n) cnt++;
                if(j-2>=0 and i-1>=0) cnt++;
                if(j+2<m and i-1>=0) cnt++;
                if(j-1>=0 and i-2>=0) cnt++;
                if(j+1<m and i-2>=0) cnt++;
                ans+=total-cnt;
            }
        }
        return ans;
    }
};