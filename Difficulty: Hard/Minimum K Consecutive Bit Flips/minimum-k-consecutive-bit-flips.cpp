class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
       int n = arr.size();
    vector<int> isFlipped(n, 0);
    int flip = 0, count = 0;

    for (int i = 0; i < n; i++) {
        if (i >= k) flip ^= isFlipped[i - k]; // remove expired flip

        if ((arr[i] ^ flip) == 0) { // need to flip
            if (i + k > n) return -1;
            count++;
            flip ^= 1;
            isFlipped[i] = 1;
        }
    }
    return count;
    }
};