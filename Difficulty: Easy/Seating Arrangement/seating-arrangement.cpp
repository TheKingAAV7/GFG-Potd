class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &arr) {
        // code here
        int n= arr.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                bool lef, rig;
                lef= rig= true;
                if(i-1>=0)
                lef= (i-1>=0 and arr[i-1]==0);
                if(i+1<n)
                rig= (i+1<n and arr[i+1]==0);
                if(lef and rig) {
                    arr[i]=1;
                    cnt++;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1] and arr[i]==1) return false;
        }
        // cout<<cnt<<endl;
        return cnt>=k;
        
    }
};