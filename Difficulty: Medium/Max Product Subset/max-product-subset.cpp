
#define ll long long
class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        int n= arr.size();
        ll mod=1e9+7;
        ll mx=*max_element(arr.begin(),arr.end());
        bool nopos=false;
        bool noneg=false;
        if(mx<=0) nopos=true;
        
        ll pos=1ll;
        ll ng= 1ll;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0) pos= (pos*arr[i])%mod;
        }
        
        
        vector<ll>neg;
        for(ll i:arr ){
            if(i<0) neg.push_back(i);
        }
        if(neg.size()==0) noneg=1;
        int negsz=neg.size();
        if(negsz%2==0){
            for(ll i:neg)  ng=(ng*i)%mod;
        }
        else{
            sort(neg.begin(),neg.end());
            for(int i=0;i<neg.size()-1;i++) ng=(ng*neg[i])%mod;
        }
        if(noneg and nopos) return 0ll;
        if(nopos){
            // cout<<"YES"<<endl;
            if(neg.size()==1) return max(neg[0],mx);
            return ng%mod;
        }
        if(noneg){
            return pos;
        }
        // cout<<"YES "<<ng<<" "<<pos<<endl;
        
        return (1ll*ng*pos)%mod;
        
        
        
    }
};
