class SegmentTree{
    public:
    int n;
    vector<int>st;
    SegmentTree(int n){
        this->n=n;
        st.resize(4*n,0);
    }
    
    void up(int idx, int lef, int rig, int i, int val){
        if(lef>rig) return ;
        if(lef==rig){
            st[idx]+=val;
            return;
        }
        int mid=(lef+rig)>>1;
        if(i<=mid) up(2*idx+1,lef,mid,i,val);
        else up(2*idx+2,mid+1,rig,i,val);
        st[idx]=st[2*idx+1]+st[2*idx+2];
        return;
    }
    
    int query(int idx, int lef, int rig, int left, int right){
        if(lef>rig || left>right) return 0;
        if(lef==left and rig==right) return st[idx];
        int mid=(lef+rig)>>1;
        if(right<=mid)  return query(2*idx+1,lef,mid,left,right);
        if((mid+1)<=left) return query(2*idx+2,mid+1,rig,left,right);
        int lefsm= query(2*idx+1,lef,mid,left,mid);
        int rigsm= query(2*idx+2,mid+1,rig,mid+1,right);
        return lefsm+rigsm;
    }
};

class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int MAXI= 1e4+1;
        SegmentTree tree= SegmentTree(MAXI);
        // find all greater
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            cnt=tree.query(0,0,MAXI,arr[i]+1,1e4); 
            ans+=cnt;
            tree.up(0,0,MAXI,arr[i],1);
        }
        return ans;
        
        
    }
};