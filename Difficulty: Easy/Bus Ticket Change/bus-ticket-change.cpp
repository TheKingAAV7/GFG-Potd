class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // 5 10  555
        int n=arr.size();
        int cnt5=0;
        int cnt10=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==5) cnt5++;
            else if(arr[i]==10){
                if(cnt5==0) return false;
                cnt5--;
                cnt10++;
            }
            else{
                if(cnt5>=1 and cnt10>=1){
                    cnt5--;
                    cnt10--;
                }
                else if(cnt5>=3){
                    cnt5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};