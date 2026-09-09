class Solution {
  public:
  int find(int n){
      int a=0;
      while(n>0){
        int x=n%10;
        n=n/10;
        a+=x;
      }
      return a;
  }

  int convert(string n,int i){
      int teg=0;
      int j=0;
      while(j<i){
          teg=(teg*10)+(n[j]-'0');

          j++;
      }
      teg=(teg*10)+((n[j]-'0')-1);

      j++;
      while(j<n.size()){
          teg=(teg*10)+9;
          j++;

      }
      return teg;
  }
    int findMax(int n) {
        string g=to_string(n);
        int sz=g.size();
        int ans=0;
        int curr=0;
        for(int i=0;i<sz;i++){
           int q= convert(g,i);
           int z=find(q);
            if(z>=curr){
                ans=q;
                curr=z;
            }
        }



        if(find(n)>=curr){
            return n;
        }
        return ans;
    }
};