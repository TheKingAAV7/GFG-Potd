//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
      Node* ans1=NULL,*ans2=NULL;
      Node* p, *q;
      int cnt=0;
      while(head){
          if(cnt%2==0){
              if(!ans1){
                  ans1= new Node(head->data);
                  p=ans1;
              }
              else{
                  p->next= new Node(head->data);
                  p=p->next;
              }
              
          }
          else{
               if(!ans2){
                  ans2= new Node(head->data);
                    q=ans2;
              }
              else{
                  q->next= new Node(head->data);
                  q=q->next;
              }
              
          }
          
          cnt++;
          head=head->next;
      }
   
     return {ans1, ans2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends