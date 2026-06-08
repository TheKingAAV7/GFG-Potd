/* Structure of a Linked List node
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
    Node* rev(Node* head){
        Node* node=head, *prev=NULL;
        while(node){
            Node* nxt=node->next;
            node->next=prev;
            prev=node;
            node=nxt;
        }
        return prev;
    }

    Node *compute(Node *head) {
        // code here
        Node* nhead=rev(head);
        Node* node=nhead->next, *prev=nhead;

        while(node){
            if(node->data>=prev->data){
                prev->next=node;
                prev=node;
            }
            node=node->next;
        }
        prev->next=NULL;

        return rev(nhead);
        
    }
};