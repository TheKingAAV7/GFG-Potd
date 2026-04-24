class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>st;
        for(int i=0;i<n;i++){
            st.push_back(arr[i]);
            while(st.size()>=2){
                int a= st.back();
                int b= st[st.size()-2];
                if(a*b<0){
                    if(abs(a)==abs(b)){
                        st.pop_back();
                        st.pop_back();
                    }
                    else{
                        if(abs(a)>abs(b)){
                            st.pop_back();
                            st.pop_back();
                            st.push_back(a);
                        }
                        else{
                            st.pop_back();
                        }
                    }
                }
                else break;
            }
        }
        return st;
    }
};