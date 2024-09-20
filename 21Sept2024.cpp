class Solution {
  public:
    Node *copyList(Node *head) {
        unordered_map<int, Node*>mp;
        Node* tmp=head;
        Node* ans=NULL;
        Node* p=ans;
        while(head!=NULL){
        //    if(head->random) cout<<head->data<<" "<<head->random->data<<endl;
            if(!ans) {
                ans=new Node(head->data);
                p=ans;
                
                mp[p->data]=p;
            }
            else{
                p->next= new Node(head->data);
                 p=p->next;
                 mp[p->data]=p;
                
            }
            head=head->next;
           
        }
        while(tmp!=NULL){
            if(tmp->random){
                mp[tmp->data]->random = mp[tmp->random];
            }
            tmp=tmp->next;
        }
        
       
        return ans;
    }
};