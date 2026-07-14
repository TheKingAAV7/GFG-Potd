#define ll long long
class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        ll mx= *max_element(arr.begin(),arr.end());
        int n= arr.size();
        ll lo=1, hi=mx;
        auto f=[&](ll curx)->bool{
          ll pcurx=curx;
          for(int i=0;i<n;i++){
              if(curx>arr[i]) curx+=abs(arr[i]-curx);
              else curx-=abs(curx-arr[i]);
              if(curx>=mx) return true;
              if(curx<0ll) return  false;
          }  
        //   if(pcurx<4) cout<<curx<<endl;
          return true;
        };
        ll ans=hi;
        while(lo<=hi){
            ll mid= (lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};