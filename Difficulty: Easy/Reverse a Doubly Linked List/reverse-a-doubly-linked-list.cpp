/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
      Node* tail= head;
      Node* front=head;
      int cnt=1;
      while(tail->next!=NULL){
          cnt++;
          tail=tail->next;
      }
      int lp=cnt/2;
      while(lp--){
          swap(front->data,tail->data);
          front=front->next;
          tail=tail->prev;
      }
      
      return head;
      
      
        
    }
};