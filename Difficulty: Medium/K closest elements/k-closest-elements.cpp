class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n=arr.size();
        vector<int>ans;
        auto it=lower_bound(arr.begin(),arr.end(),x);
        if(it==arr.end()){
            while(k--){
                ans.push_back(arr.back());arr.pop_back();
            }
            return ans;
        }
        int idx=(it-arr.begin());
        if((idx-1)>=0 and abs(arr[idx-1]-x)<abs(arr[idx]-x)){
            idx--;
        }
        
        int lef=idx,rig=idx+1;
        
        
        while(lef>=0 and rig<n ){
            if(arr[lef]==x){
                lef--;
                continue;
            }
            if(arr[rig]==x){
                rig++;
                continue;
            }
            
            if(abs(x-arr[lef])<abs(x-arr[rig])){
                k--;
                ans.push_back(arr[lef]);
                lef--;
                if(k==0) break;
            }
            else{
                ans.push_back(arr[rig]);
                k--;
                rig++;
                if(k==0) break;
            }
            
        }
        if(k==0) return ans;
        while(lef>=0 and k--){
            ans.push_back(arr[lef--]);
        }
        while(rig<n and k--){
            ans.push_back(arr[rig++]);
        }
        return ans;
        
        
        
    }
};