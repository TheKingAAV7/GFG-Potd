class Solution {
  public:
    int maxPeopleDefeated(int p) {
            // 1 4
        int cnt=0;
        int cur=1;
        while(p>=(cur*cur)) {
            cnt++;
            p-=(cur*cur);
            cur++;
        }
        return cnt;
    }
};
