/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
       Node* tail= head;
       while(tail->next!=head){
           tail=tail->next;
       }
       if(data<(head->data) || data>(tail->data)){
           Node* tmp= new Node(data);
           tail->next=tmp;
           tmp->next=head;
           if(data<(head->data)) return tmp;
           return head;
       }
       Node* prev=tail;
       Node* p=head;
       while(data>(p->data)){
           prev=p;
           p=p->next;
       }
       Node* tmp= new Node(data);
       prev->next=tmp;
       tmp->next=p;
       return head;
       
        
    }
};