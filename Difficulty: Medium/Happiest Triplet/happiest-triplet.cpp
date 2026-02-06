class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        // 23000 1600
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int n=a.size();
        int m=b.size();
        int o=c.size();
        int sm=INT_MAX;
        int diff=INT_MAX;
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            auto it1=lower_bound(b.begin(),b.end(),a[i]);
            auto it2=lower_bound(c.begin(),c.end(),a[i]);
            if(it1!=b.end() and it2!=c.end()){
             //   cout<<a[i]<<" "<<*it1<<" "<<*it2<<endl;
                vector<int>tmp={a[i],*it1,*it2};
                sort(tmp.begin(),tmp.end(),greater<int>());
                int cursm= tmp[0]+tmp[1]+tmp[2];
                int curdiff= tmp[0]-tmp[2];
                if(curdiff<diff){
                    ans=tmp;
                    diff=curdiff;
                    sm=cursm;
                }
                else if(curdiff==diff){
                    if(cursm<sm){
                        sm=cursm;
                        ans=tmp;
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            auto it1=lower_bound(a.begin(),a.end(),b[i]);
            auto it2=lower_bound(c.begin(),c.end(),b[i]);
            if(it1!=b.end() and it2!=c.end()){
             //   cout<<a[i]<<" "<<*it1<<" "<<*it2<<endl;
                vector<int>tmp={b[i],*it1,*it2};
                sort(tmp.begin(),tmp.end(),greater<int>());
                int cursm= tmp[0]+tmp[1]+tmp[2];
                int curdiff= tmp[0]-tmp[2];
                if(curdiff<diff){
                    ans=tmp;
                    diff=curdiff;
                    sm=cursm;
                }
                else if(curdiff==diff){
                    if(cursm<sm){
                        sm=cursm;
                        ans=tmp;
                    }
                }
            }
        }
        
        
        for(int i=0;i<o;i++){
            auto it1=lower_bound(a.begin(),a.end(),c[i]);
            auto it2=lower_bound(b.begin(),b.end(),c[i]);
            if(it1!=b.end() and it2!=c.end()){
             //   cout<<a[i]<<" "<<*it1<<" "<<*it2<<endl;
                vector<int>tmp={c[i],*it1,*it2};
                sort(tmp.begin(),tmp.end(),greater<int>());
                int cursm= tmp[0]+tmp[1]+tmp[2];
                int curdiff= tmp[0]-tmp[2];
                if(curdiff<diff){
                    ans=tmp;
                    diff=curdiff;
                    sm=cursm;
                }
                else if(curdiff==diff){
                    if(cursm<sm){
                        sm=cursm;
                        ans=tmp;
                    }
                }
            }
        }
        return ans;
        
    }
};