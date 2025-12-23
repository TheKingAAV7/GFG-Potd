class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int cnt=0;
        for(int i:arr){
            cnt+=(i<=x);
        }
        return cnt;
    }
};