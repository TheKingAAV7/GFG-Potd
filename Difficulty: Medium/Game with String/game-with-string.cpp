class Solution {
  public:
    int minValue(string &s, int k) {
        priority_queue<int>q;
        vector<int>v(26,0);
        for(char c:s) v[c-'a']++;
        
        for(int i=0;i<26;i++){
            if(v[i]>0)q.push(v[i]);
        }
        
        while(!q.empty() and k--){
            int freq=q.top();q.pop();
            freq--;
            if(freq>0) q.push(freq);
        }
        int ans=0;
        while(!q.empty()){
            int x=q.top();q.pop();
            ans+=(x*x);
        }
        return ans;
    }
};