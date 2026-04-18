class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        int cur=x;
        int cnt=1;
        if(y==1) return true;
        if(x==1) return y==1;
        while(pow(x,cnt)<y) cnt++;
        return pow(x,cnt)==y;
        
    }
};