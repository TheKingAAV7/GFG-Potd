class Solution {
  public:
    int hIndex(vector<int>& arr) {
        // code here
        int MAX=*max_element(arr.begin(),arr.end()) + 1;
        int n=arr.size();
        // sort(arr.begin(),arr.end());
        // for(int i=n-1;i>=0;i--){
        //     int rig= (n-i);
        //     if(rig>=arr[i]) return arr[i];
        // }
        int mp[MAX];
        memset(mp,0,sizeof(mp));
        int cnt=0;
       
        for(int &i:arr) mp[i]++;
        for(int i=MAX-1;i>=0;i--){
            cnt+=mp[i];
            if(cnt>=i) return i;
        }
        return n;
        
        
        
    }
};