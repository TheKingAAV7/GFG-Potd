//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node* prev=NULL;
        if(k==1) return head;
        Node* head1=head;
        int cnt1=k;
        while(cnt1--){
            Node* nxt=head1->next;
            head1->next=prev;
            prev=head1;
            head1=nxt;
        }
        Node* ans=prev;
        Node* lastnode=head;
        
        int cnt=1;
        prev=NULL;
        Node* first=NULL;
        bool f=false;
        while(head1!=NULL){
            if(cnt%k==0){
                Node* nx=head1->next;
                head1->next=prev;
                prev=head1;
                head1=nx;
                lastnode->next=prev;
                lastnode=first;
                prev=NULL;
                f=false;
                cnt=1;
            }
            else{
                if(!f){
                    first=head1;
                    f=!f;
                }
                Node* nx=head1->next;
                head1->next=prev;
                prev=head1;
                head1=nx;
                cnt++;
            }
            
            
        }
        if(prev!=NULL){
        lastnode->next=prev;
        }
        
        
        return ans;
        
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends