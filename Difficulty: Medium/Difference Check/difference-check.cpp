class Solution {
  public:
    int minDifference(vector<string> &arr) {
        vector<int> v;
        
        for(auto i : arr){
            int a = 0;
            
            string hour = i.substr(0,2);
            string minute = i.substr(3,2);
            string second = i.substr(6,2);
            
            a += (stoi(hour)*3600);
            a += (stoi(minute)*60);
            a += stoi(second);
            
            v.push_back(a);
        }
        
        sort(v.begin(), v.end());
        
        int ans = INT_MAX;
        
        for(int i = 0;i<v.size()-1;i++){
            ans = min(ans,abs(v[i]-v[i+1]));
        }
        
        int day = 24*3600;
        ans = min(ans, day - (v.back() - v[0]));
        
        return ans;
    }
};