class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size();
        deque<int>p;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]=='P') p.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(arr[i]=='T'){
                while(!p.empty() and (p.front()<i) and (i-p.front())>k){
                    p.pop_front();
                }
                if(p.empty()) break;
                if(abs(p.front()-i)<=k) {
                    p.pop_front();
                    cnt++;
                }
            }
            
        }
        return cnt;
        
    }
};