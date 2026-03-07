class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int mp[3001]={0};
        int n=arr.size();
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(int i=1;i<=3000;i++){
            if(mp[i]<=0) continue;
            mp[i]--;
            for(int j=i;j<=3000;j++){
                if(mp[j]>0){
                    mp[j]--;
                    double req= sqrt(1.0*i*i + 1.0*j*j);
                    if(ceil(req)==floor(req)){
                     int x= floor(req);
                     if(mp[x]>0) return true;
                    }
                    mp[j]++;
                }
            }
            mp[i]++;
        }
        return false;
        
    }
};