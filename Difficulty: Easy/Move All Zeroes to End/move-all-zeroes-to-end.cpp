class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int prev=-1;
        deque<int>dq;
        for(int i=0;i<n;i++){
            if(arr[i]==0 ) dq.push_back(i);
            else{
                if(dq.size()) {
                int id= dq.front();
                dq.pop_front();
                swap(arr[i],arr[id]);
                dq.push_back(i);
                }
            }
        }
        return ;
        
    }
};