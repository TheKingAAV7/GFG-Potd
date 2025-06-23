class Solution {

  public:
    string minSum(vector<int> &arr) {
        int n=arr.size();
      sort(arr.begin(),arr.end());
      string a="",b="";
      for(int i=0;i<n;i++){
          if(i%2==0) a.push_back(char(arr[i]+'0'));
          else b.push_back(char(arr[i]+'0'));
      }
      auto add=[&](string &a, string &b)->string{
          string ans="";
          int n=a.length(),m=b.length();
          int carry=0;
          int i=n-1,j=m-1;
          while(i>=0 and j>=0){
              int cur=(a[i]-'0'+ b[j]-'0')+carry;
              ans.push_back((cur%10)+'0');
              if(cur>9){   
                  cur/=10;
                  carry=cur;
              }
              else carry=0;
              i--;
              j--;
          }
          while(i>=0){
              int cur= (a[i]-'0')+carry;
              ans.push_back((cur%10)+'0');
              if(cur>9){   
                  cur/=10;
                  carry=cur;
              }
              else carry=0;
              i--;
          }
          while(j>=0){
              int cur= (b[j]-'0')+carry;
              ans.push_back((cur%10)+'0');
              if(cur>9){   
                  cur/=10;
                  carry=cur;
              }
              else carry=0;
              j--;
          }
          if(carry!=0){
              ans.push_back(char(carry+'0'));
          }

          while(ans.size()>0 and ans.back()=='0'){
              ans.pop_back();
          } 
          if(ans=="") return "0";
          reverse(ans.begin(),ans.end());
          return ans;
      };
      string ans=add(a,b);
      return ans;
    }
};