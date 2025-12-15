class Solution:
    def areRotations(self, s1, s2):
        # code here
        s1=s1+s1
        res= s2 + '#' + s1
        n= len(res)
        z=[0]*n
        l=0
        r=-1
        m=len(s2)
        for i in range(1,n):
            
            if i<=r:
                z[i]=min(r-i+1,z[i-l])
            while i+z[i]<n and res[z[i]]==res[i+z[i]]:
                z[i]+=1
            
            if (i+z[i]-1) > r:
                r=i+z[i]-1
                l=i
                
                    
        
        
        for i in range(m+1,n):
            if z[i]==m:
                return True
        
        return False