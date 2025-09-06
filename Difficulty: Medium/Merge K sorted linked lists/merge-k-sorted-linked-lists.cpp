/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        int n=arr.size();
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<>>pq;
        for(auto it:arr){
            pq.push({it->data,it});
        }
        Node* ans=NULL;
        Node* p=NULL;
        while(!pq.empty()){
            Node* tmp=pq.top().second;
            pq.pop();
            if(!ans){
                ans=tmp;
                p=tmp;
            }
            else{
                p->next=tmp;
                p=p->next;
            }
            tmp=tmp->next;
            if(tmp) pq.push({tmp->data,tmp});
        }
        return ans;
        
    }
};