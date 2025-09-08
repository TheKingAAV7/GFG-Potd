class Solution {
  
  public:
    void merge(vector<int>&arr,int l, int mid, int r){
        int lefsz=mid-l+1;
        int rigsz=r-(mid+1)+1;
        vector<int>lef;
        vector<int>rig;
        for(int i=0;i<lefsz;i++){
            lef.push_back(arr[l+i]);
        }
        for(int j=0;j<rigsz;j++){
            rig.push_back(arr[mid+1+j]);
        }
        int i=0,j=0;
        int k=l;
        while(i<lefsz and j<rigsz){
            if(lef[i]<=rig[j]){
                arr[k]=lef[i];
                i++;
                k++;
            }       
            else{
                arr[k]=rig[j];
                j++;
                k++;
            }
        }
        while(i<lefsz) arr[k++]=lef[i++];
        while(j<rigsz) arr[k++]=rig[j++];
        
        return;
    }
    void mergeSort(vector<int>& arr, int l, int r) {
       if(l<r){
           int mid=(l+r)>>1;
           mergeSort(arr,l,mid);
           mergeSort(arr,mid+1,r);
           merge(arr,l,mid,r);
       }
       return;
        
    }
};