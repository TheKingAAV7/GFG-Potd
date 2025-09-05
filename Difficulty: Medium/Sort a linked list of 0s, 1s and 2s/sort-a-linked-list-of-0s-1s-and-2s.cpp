/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
     Node* ans=NULL;
     Node* p=NULL;
     for(int i=0;i<3;i++){
     for(Node* tmp=head;tmp!=NULL;tmp=tmp->next){
         
        if(tmp->data==i){
            if(!ans){ 
                
            ans=new Node(tmp->data);
            p=ans;
            }
            else {
            Node* t= new Node(tmp->data);
            ans->next=t;
            ans=t;
        }
        }
        
     }
     }
     return p;
    }
};
