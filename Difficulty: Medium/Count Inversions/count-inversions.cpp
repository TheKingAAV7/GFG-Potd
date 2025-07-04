

class Solution {
  private:
  vector<int>segtree;
  void up(int idx, int lef, int rig, int ind, int val){
      if(lef==rig){
          segtree[idx]+=val;
          return;
      }
      int mid=(lef+rig)>>1;
      if(ind<=mid) up(2*idx+1,lef,mid,ind,val);
      else up(2*idx+2,mid+1,rig,ind,val);
      segtree[idx]= segtree[2*idx+1]+segtree[2*idx+2];
      return;
  }
  int query(int idx, int lef, int rig, int l ,int r){
      if (l > r)  
        return 0;

      if(lef==l and rig==r) return segtree[idx];
      int mid=(lef+rig)>>1;
      if(r<=mid){
          return query(2*idx+1,lef, mid, l, r);
      }
      else if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r);
      else{
          int left=query(2*idx+1,lef,mid,l,mid);
          int right=query(2*idx+2,mid+1,rig,mid+1,r);
          return left+right;
      }
      return 0;
      
  }
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        int ans=0;
        int maxi=*max_element(arr.begin(),arr.end());
        segtree.resize(maxi*4,0);
        for(int i=0;i<n;i++){
            int l=0,r=arr[i]-1;
            ans+=query(0,0,maxi,arr[i]+1,maxi);
            up(0,0,maxi,arr[i],1);
        }
        
        return  ans;
    }
};