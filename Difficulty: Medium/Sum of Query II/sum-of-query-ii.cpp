// User function Template for C++

class Solution {
  private:
  vector<int>segtree;
  int bt(int i, int lef, int rig, int arr[],int n){
      if(lef==rig){
        segtree[i]=arr[lef];
        return segtree[i];
      }
      int mid=(lef+rig)/2;
      int left=bt(2*i+1,lef,mid,arr,n);
      int right=bt(2*i+2,mid+1,rig,arr,n);
      segtree[i]=left+right;
      return segtree[i];
  }
  int sm(int i, int lef, int rig, int left, int right){
      if(lef==left and right==rig){
          return segtree[i];
      }
      int mid=(lef+rig)/2;
      if(lef<=left and right<=mid){
          return sm(2*i+1,lef,mid,left,right);
      }
      else if((mid+1)<=left  and right<=rig){
          return sm(2*i+2,mid+1,rig,left,right);
      }
      int le=sm(2*i+1,lef,mid,left,mid);
      int ri=sm(2*i+2,mid+1,rig,mid+1,right);
      return le+ri;
  }
  public:
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
     segtree.resize(4*n,0);
     vector<int>ans;
     bt(0,0,n-1,arr,n);
     for(int i=0;i<2*q;i+=2){
        //  cout<<queries[i]<<" "<<queries[i+1]<<endl;
         int l=queries[i]-1;
         int r=queries[i+1]-1;
          
         int tmp=sm(0,0,n-1,l,r);
         ans.push_back(tmp);
         
         
         
     }
     return ans;
        
    }
};