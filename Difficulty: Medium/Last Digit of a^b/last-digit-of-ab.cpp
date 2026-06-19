class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        /*
        0->1
        1->1
        2 ->4 -> 8 -> 6
        3-> 9 -> 7 -> 1
        4-> 6
        5
        6
        7->9->3->1
        8->4->2->6
        9->1
        */
        if(a.back()=='0') return 0;
        if(b.length()==1 and b[0]=='0') return 1;
        vector<vector<int>>v={
            {0},
            {1},
            {6,2,4,8},
            {1,3,9,7},
            {6,4},
            {5},
            {6},
            {1,7,9,3},
            {6,8,4,2},
            {1,9}
        };
        int alst = a.back()-'0';
        int blst= b.back()-'0';
        int bslst = 0;
        if(b.length()>=2) bslst= b[b.length()-2]-'0';
        
        int po= bslst*10+blst;
        int sz= v[alst].size();
        int mod= po%sz;
        // cout<<mod<<endl;
        return v[alst][mod];
        
        
    }
};