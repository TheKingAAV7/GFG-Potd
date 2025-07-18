
#include<bits/stdc++.h>
#include <numeric> // for std::gcd in C++17 or later
using namespace std;
class Solution {
  private:
  int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}


int lcm_of_three(int a, int b, int  c) {
    return lcm(lcm(a, b), c);
}

  public:
    int lcmTriplets(int n) {
        if (n < 3) return n;
        if (n % 2 != 0) return n * (n - 1) * (n - 2);
        return n % 3 != 0 ? n * (n - 1) * (n - 3)
                          : (n - 1) * (n - 2) * (n - 3);
    
    }
};