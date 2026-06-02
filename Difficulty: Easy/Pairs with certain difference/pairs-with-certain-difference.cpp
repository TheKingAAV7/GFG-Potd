class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        
        sort(arr.begin(), arr.end()); //Due to this T.C => O(nlogn)
        
        for (int i = arr.size()-1; i > 0; i--) {
            if (arr[i] - arr[i-1] < k) {
                sum += (arr[i] + arr[i-1]);
                i--;
            }
        }
        
        return sum;
    }
};