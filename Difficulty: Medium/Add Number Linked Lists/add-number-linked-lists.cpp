/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        
        function<Node*(Node* )>rev=[&](Node* cur){
          
          Node* prev= NULL;
          Node* p= cur;
          while(p!=NULL){
              Node* nxt= p->next;
              p->next= prev;
              prev= p;
              p=nxt;
          }
          return prev;
        };
        head1=rev(head1);
        head2=rev(head2);
        int carry=0;
        Node* ans= NULL;
        Node* p= NULL;
        while(head1 and head2){
         int cursm= head1->data+ head2->data+ carry;
         int curval= cursm%10;
         cursm/=10;
         carry=cursm;
         Node* curnod= new Node(curval);
         if(!ans){
             ans= curnod;
             p= curnod;
         }
         else{
             p->next= curnod;
             p=p->next;
         }
         head1=head1->next;
         head2=head2->next;
        }
        while(head1){
            int cursm= head1->data+ carry;
         int curval= cursm%10;
         cursm/=10;
         carry=cursm;
         Node* curnod= new Node(curval);
         if(!ans){
             ans= curnod;
             p= curnod;
         }
         else{
             p->next= curnod;
             p=p->next;
         }
         head1=head1->next;
        }
        while(head2){
            int cursm= head2->data+ carry;
         int curval= cursm%10;
         cursm/=10;
         carry=cursm;
         Node* curnod= new Node(curval);
         if(!ans){
             ans= curnod;
             p= curnod;
         }
         else{
             p->next= curnod;
             p=p->next;
         }
         head2=head2->next;
        }
        
        if(carry>0){
            p->next= new Node(carry);
        }
        Node* fin= rev(ans);
        while(fin and fin->data==0) fin= fin->next;
        return fin;
    }
};