class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int lo=0;
        int hi=1e9;
        int ans=-1;
        auto f=[&](int mid)->bool{
          
          auto it1= upper_bound(a.begin(),a.end(),mid);
          auto it2= upper_bound(b.begin(),b.end(),mid);
          it1--;
          it2--;
          int idx= it1-a.begin()+1;
          int idx2= it2-b.begin()+1;
          int total = idx+idx2;
        //   if(*it1== mid) total++;
        //   if(*it2==mid) total++;
        //   if(mid<=12){
        //       cout<<idx<<" "<<idx2<<endl;
        //   cout<<mid<<" "<<total<<endl;
        //   cout<<endl;
        //   }
          return total>=k;
          
        };
        while(lo<=hi){
            int mid=(lo+hi)>>1;
            if(f(mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};