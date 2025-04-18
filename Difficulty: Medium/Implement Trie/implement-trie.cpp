//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Node{
    public:
    bool isend;
    vector<Node*>children;
    Node(){
        isend=false;
        children.resize(26,NULL);
        
    }
};
class Trie {
  public:
    Node* root;
    Trie() {
        root= new Node();
    }

    void insert(string &word) {
        int n=word.length();
        Node* crawl=root;
        for(int i=0;i<n;i++){
            if(crawl->children[word[i]-'a']==NULL){
                crawl->children[word[i]-'a']=new Node();
            }
            crawl=crawl->children[word[i]-'a'];
        }
        crawl->isend=true;
    }

    bool search(string &word) {
        Node* crawl=root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(crawl->children[word[i]-'a']==NULL) return false;
            crawl=crawl->children[word[i]-'a'];
        }
        return crawl->isend;
    }

    bool isPrefix(string &word) {
       Node* crawl=root;
       int n=word.length();
       for(int i=0;i<n;i++){
           if(crawl->children[word[i]-'a']!=NULL){
               crawl=crawl->children[word[i]-'a'];
           }
           else return false;
       }
       return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends