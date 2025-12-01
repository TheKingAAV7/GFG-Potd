
/*
Copied.....

*/
class TrieNode{
    public:
    TrieNode *one=NULL;
    TrieNode *two=NULL;
  
    int cnt=0;
    
};

void insert(int x, int &msb, TrieNode* root){
    TrieNode* p= root;
    for(int i=msb-1;i>=0;i--){
        
        if((x&(1<<i))){
            
            if(!p->one)
            p->one = new TrieNode();
            p=p->one;
        }
        else{
            if(!p->two)
            p->two= new TrieNode();
            p= p->two;
        }
        p->cnt+=1;
    }
    return;
}


int f(TrieNode* root, int k, int x, int &msb){
    TrieNode* p= root;
    int tmp= x;
    int ans=0;
    for(int i=msb-1;i>=0;i--){
        if(!p) break;
        int bitnum= (x>>i)&1;
        int bitK= (k>>i)&1;
        
        if(bitK==1){
            if(bitnum==1 ){
                if(p->one)
                ans+= p->one->cnt;
                p= p->two;
            }
            else {
                if(p->two)
                ans+=(p->two->cnt);
                p= p->one;
            }
            
        }
        else{
            if(bitnum==1) p= p->one;
            else p=p->two;
        }
    }
     return ans;
}


class Solution {
  public:
    int cntPairs(vector<int>& arr, int k) {
      int n=arr.size();
      int mx= *max_element(arr.begin(),arr.end());
      mx=max(mx,k);
      int msb= floor(log2((double)(mx))) + 1;
      TrieNode* root= new TrieNode();
     // insert(arr[n-1],msb,root);
      int ans=0;
      for(int i=0;i<n;i++){
          
          int cur= f(root,k,arr[i],msb);
         // cout<<cur<<endl;
         ans+= cur;
          
          insert(arr[i],msb,root);
      }
      
       return ans; 
    }
};