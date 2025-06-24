// User function Template for C++

class Solution {
  private:
  vector<int>segtree;
  vector<int>nums;
  
  void bt(int i, int lef , int rig){
      if(lef==rig){
          segtree[i]=nums[lef];
          return;
      }
      int mid=(lef+rig)/2;
      bt(2*i+1,lef, mid);
      bt(2*i+2, mid+1,rig);
      segtree[i]=segtree[2*i+1]+segtree[2*i+2];
      return ;
  }
  int q(int i, int lef, int rig, int l, int r){
      if(lef==l and rig==r) return segtree[i];
      int mid=(lef+rig)/2;
      if(r<=mid) return q(2*i+1,lef, mid, l, r);
      else if((mid+1)<=l) return q(2*i+2,mid+1, rig, l ,r);
      int left=q(2*i+1,lef,mid,l, mid);
      int right=q(2*i+2,mid+1,rig, mid+1, r);
      return left+right;
  }
  
  public:
    vector<int> querySum(int n, int arr[], int Q, int queries[]) {
       
        nums.resize(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++) nums[i]=arr[i];
        segtree.resize(4*n,0);
        bt(0,0,n-1);
        for(int i=0;i<2*Q;i+=2){
            int l=queries[i]-1;
            int r=queries[i+1]-1;
            int tmp=q(0,0,n-1,l,r);
            ans.push_back(tmp);
        }
        return ans;
    }
};