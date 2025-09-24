#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
public:
    queue<int> q;
    deque<int> minD; 
    deque<int> maxD; 

    void enqueue(int x) {
        q.push(x);

        while (!minD.empty() && minD.back() > x) minD.pop_back();
        minD.push_back(x);

       
        while (!maxD.empty() && maxD.back() < x) maxD.pop_back();
        maxD.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return; 
        int val = q.front();
        q.pop();
        if (!minD.empty() && minD.front() == val) minD.pop_front();
        if (!maxD.empty() && maxD.front() == val) maxD.pop_front();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minD.front();
    }

    int getMax() {
        return maxD.front();
    }
};
