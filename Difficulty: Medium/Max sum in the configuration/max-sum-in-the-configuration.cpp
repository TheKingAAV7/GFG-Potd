class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        
        long long arrSum = 0;
        long long currVal = 0;
        
        for(int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += (long long)i * arr[i];
        }
        
        long long res = currVal;
        
        for(int k = 1; k < n; k++) {
            currVal = currVal + arrSum - (long long)n * arr[n - k];
            res = max(res, currVal);
        }
        
        return res;
    }
};