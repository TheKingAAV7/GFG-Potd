class Solution {
  public:
  
    vector<int>st;
    void update(int idx, int lef, int rig, int i){
        if(lef==rig){
            st[idx]+=1;
            return;
        }
        int mid=(lef+rig)>>1;
        if(i<=mid) update(2*idx+1,lef,mid,i);
        else update(2*idx+2,mid+1,rig,i);
        st[idx]=st[2*idx+1]+st[2*idx+2];
        return;
    }
    
    int query(int idx, int lef, int rig, int l, int r){
        if(lef>rig) return 0; 
        if(lef==l and rig==r) return st[idx];
        int mid= (lef+rig)>>1;
        if(r<=mid) return query(2*idx+1,lef,mid,l,r);
        else if((mid+1)<=l) return query(2*idx+2,mid+1,rig,l,r);
        
        int a1= query(2*idx+1,lef,mid,l,mid);
        int a2= query(2*idx+2,mid+1,rig,mid+1,r);
        return a1+a2;
    }
    
    
    int countSubstring(string& s) {
        /*
        
        x-prev>0
        x>-1
        
        -1 0 1 0
        0 1 1 0
        
        */
        
        int n= s.length();
        vector<int>pref(n,0);
        int cur=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') cur--;
            else cur++;
            pref[i]=cur;
        }
        
        // for(int i:pref) cout<<i<<" ";
        // cout<<endl;
        int sz= 2*n+2;
        st.resize(4*sz,0);
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            int toup=pref[i]+n;
            // cout<<toup<<endl;
            update(0,0,sz,toup);
            int prev= (i-1>=0?pref[i-1]:0);
            int req= prev+n;
            int ans=0;
            if(req+1<=sz)
            ans=query(0,0,sz,req+1,sz);
            
            cnt+=ans;
            // cout<<req<<endl;
            // for(int j=i;j<n;j++){
            //     if(pref[j]>req) cnt++;
            // }
        }
        
        return cnt;
        
    }
};