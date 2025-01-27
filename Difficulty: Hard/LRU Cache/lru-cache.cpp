//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
  map<int,pair<int,int>>mp; // time-> {x,y}
  map<int,pair<int,int>>mp1;// x-> {y,time}
  int sz=0;
  int tim=0;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        sz=cap;
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(mp1.find(key)==mp1.end()) return -1;
        int val=mp1[key].first;
        int t=mp1[key].second;
        mp.erase(t);
        mp[tim]={key,val};
        mp1[key].second=tim;
        tim++;
        return val;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(mp1.find(key)!=mp1.end()){
           int val=mp1[key].first;
           int t=mp1[key].second; 
           mp.erase(t);
           mp[tim]={key,value};
           mp1[key].first=value;
           mp1[key].second=tim;
           tim++;
        }
        else{
            if(mp.size()<sz){
                mp[tim]={key,value};
                mp1[key]={value,tim};
                tim++;
            }
            else{
                auto it=*mp.begin();
                mp.erase(mp.begin());
                auto k=it.second.first;
                mp1.erase(k);
                mp[tim]={key,value};
                mp1[key]={value,tim};
                tim++;
            }
            
            return;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends