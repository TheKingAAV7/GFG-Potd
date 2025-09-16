class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // 0 12
        stack<int>st;
        string op="+-*/^";
        int ans=0;
        for(auto it:arr){
            if(op.find(it)!=string::npos){
                //cout<<it<<endl;
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                if(it=="+")
                ans=(a+b);
                else if(it=="-") ans=(a-b);
                else if(it=="*") ans=(a*b);
                else if(it=="/"){
                double tmp=((1.0*abs(a))/(1.0*abs(b)));
                if(floor(tmp)==ceil(tmp)){
                    if(a*b < 0){
                        ans=-1*(int)tmp;
                    }
                    else ans=(int)tmp;
                }
                else{
                   if(a*b < 0){
                        ans=-1*(int)tmp -1 ;
                    }
                    else ans=(int)tmp;
                }
                }
                else ans=pow(a,b);
               // cout<<ans<<endl;
                st.push(ans);
            }
            else{
                int num=stoi(it);
                st.push(num);
            }
        }
        return st.top();
        
    }
};