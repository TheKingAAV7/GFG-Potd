/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  } 1 2 2 1   n/2 +1
}; 1 2 3 2 1  n/2 +1

2 1  

*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
       Node* p= NULL;
       
       Node* tmp=head;
       while(tmp!=NULL){
           if(!p) p= new Node(tmp->data);
           else{
               Node* nn= new Node(tmp->data);
               nn->next=p;
               p=nn;
           }
           tmp=tmp->next;
       }
       
       while(p!=NULL and head!=NULL){
           if(p->data!=head->data) return false;
           p=p->next;
           head=head->next;
       }
       return true;
       
    }
};

