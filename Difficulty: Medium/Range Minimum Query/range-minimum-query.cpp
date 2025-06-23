/* The functions which
builds the segment tree */

 int bt(int i, int lef, int rig, int arr[],int n,int segtree[]){
      if(lef==rig){
        segtree[i]=arr[lef];
        return segtree[i];
      }
      int mid=(lef+rig)/2;
      int left=bt(2*i+1,lef,mid,arr,n,segtree);
      int right=bt(2*i+2,mid+1,rig,arr,n,segtree);
      segtree[i]=min(left,right);
      return segtree[i];
  }
  int sm(int i, int lef, int rig, int left, int right,int segtree[]){
      if(lef==left and right==rig){
          return segtree[i];
      }
      int mid=(lef+rig)/2;
      if(right<=mid){
          return sm(2*i+1,lef,mid,left,right,segtree);
      }
      else if((mid+1)<=left ){
          return sm(2*i+2,mid+1,rig,left,right,segtree);
      }
      int le=sm(2*i+1,lef,mid,left,mid,segtree);
      int ri=sm(2*i+2,mid+1,rig,mid+1,right,segtree);
      return min(le,ri);
  }
int *constructST(int arr[], int n) {
    int *st = new int[4*n];
    for (int i = 0; i < 4*n; i++) {
        st[i] = INT_MAX;
    }
    bt(0, 0, n-1, arr, n, st);
    return st;
    
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    
    return sm(0,0,n-1,a,b,st);
   
}