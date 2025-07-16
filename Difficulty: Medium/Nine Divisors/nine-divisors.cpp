class Solution {
  public:
    int countNumbers(int n) {
        int cnt = 0;
        int i= 1;
        while(i*i<=n){
            int num = i*i;
            
            int temp = 0;
            for(int i=1;i*i<num;i++){
                if(num%i==0)
                    temp++;
                if(temp>4)
                    break;
            }
            
            if(temp==4)
                cnt++;
            
            i++;
        }
        
        return cnt;
    }
};