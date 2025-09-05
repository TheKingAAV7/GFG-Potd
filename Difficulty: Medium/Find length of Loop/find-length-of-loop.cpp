/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int lengthOfLoop(struct Node *head) {
        // Code here
      
        
     /* while(p!=NULL){
            cnt++;
          0*/
          unordered_map <Node* ,int> map;
    int timer=0;
    
    Node*temp=head;
    
    while(temp!=nullptr)
    {
        if(map.find(temp)!=map.end())
        {
            int val=map[temp];
            return timer-val;
        }
        
        map[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
    // Code here

    }
    
};
