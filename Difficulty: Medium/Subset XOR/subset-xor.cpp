class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        // code here
        int XOR = 0;
        for(int i=0; i<=n; i++)
        XOR = XOR^i;
        int exclude = XOR^n;
        vector<int> ans;
        for(int i=1; i<=n; i++)
        {
            if(i!=exclude)
            ans.push_back(i);
        }
        
        // The XOR of numbers from 1 to n follows this pattern:

        // If n % 4 == 0 → xor(1..n) = n
        // If n % 4 == 1 → xor(1..n) = 1
        // If n % 4 == 2 → xor(1..n) = n + 1
        // If n % 4 == 3 → xor(1..n) = 0
        // So the XOR of all numbers from 1 to n is never larger than n + 1.

        // the value exclude will lie in the range of 1 to n
        // as XOR of (1 to n) is <= (n+1)
        // exclude = XOR ^ n
        // This means exclude is simply the XOR of numbers from 1 to n-1, 
        // and this value always lies between 1 and n. 
        // Thus, exclude is guaranteed to be a valid element of the original subset,
        // and removing it always gives a correct solution.
        return ans;
    }
};
