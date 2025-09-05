class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &a1, vector<int> &a2,
                               vector<int> &a3) {
        // Code Here
        int las=-1;
        int n=a1.size();
        int m=a2.size();
        int o=a3.size();
        int i=0,j=0,k=0;
        vector<int>ans;
        while(i<n and j<m and k<o){
            if(a1[i]==a2[j] and a2[j]==a3[k]){
                
                if(las!=a1[i]){
                    ans.push_back(a1[i]);
                    las=a1[i];
                    
                }
                i++;
                j++;
                k++;
            }
            else{
                int mini=min(a1[i],min(a2[j],a3[k]));
                if(a1[i]==mini) i++;
                if(a2[j]==mini) j++;
                if(a3[k]==mini) k++;
            }
        }
        return ans;
        
    }
};