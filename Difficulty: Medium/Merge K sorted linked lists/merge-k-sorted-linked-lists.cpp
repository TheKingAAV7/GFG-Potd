//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    void sortLinkedList(Node* head) {
        if (!head) return; // If the list is empty, return immediately

        // Step 1: Extract data into a vector
        vector<int> values;
        Node* current = head;
        while (current != NULL) {
            values.push_back(current->data);
            current = current->next;
        }

        // Step 2: Sort the vector
        sort(values.begin(), values.end());

        // Step 3: Update the linked list with sorted values
        current = head;
        for (int value : values) {
            current->data = value;
            current = current->next;
        }
    }
    // Function to merge K sorted linked list.
    Node*FindLast(Node*root){
        Node*temp = root;
        while(temp->next != NULL){
            temp=temp->next;
        }
        return temp;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int n=arr.size();
        for(int i=0;i<n - 1;i++){
            Node*lastNode=FindLast(arr[i]);
            lastNode->next=arr[i + 1];
        }
        sortLinkedList(arr[0]);
        return arr[0];
    }
};




//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends