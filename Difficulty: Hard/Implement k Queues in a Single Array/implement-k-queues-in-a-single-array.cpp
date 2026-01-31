class kQueues {

  public:
    map<int,queue<int>>mp;
    int cnt=0;
    int n;
    
    kQueues(int N, int k) {
        // Initialize your data members
        n=N;
        
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(cnt+1<=n){ 
        mp[i].push(x);
        cnt++;
        }
        
        return;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        if(mp[i].empty()) return -1;
        int ans= mp[i].front();
        mp[i].pop();
        cnt--;
        return ans;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        return mp[i].size()==0;
    }

    bool isFull() {
        return cnt==n;
        // check if array is full
    }
};
