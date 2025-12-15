class Solution:
    def areRotations(self, s1, s2):
        
        # 2*31*31    1      
        res= s1+s1
        n=len(res)
        m=len(s2)
        hshval=0
        p=int(31)
        mod=int(1e9+7)
        po=int(0)
        for i in range(m):
            cur= ord(s2[i])-ord('a')+1
            rig=(pow(p,po,mod)*cur)%mod
            
            hshval= (hshval + rig)%mod
            po= (po+1)%mod
             
        
        #print(res,hshval,s2)
        hsh=[0]*n
        h1=0
        po=int(0)
        for i in range(n):
            cur=ord(res[i])-ord('a')+1
            rig=(pow(p,po,mod)*cur)%mod
            h1=(h1+rig)%mod
            hsh[i]=h1
            po= (po+1)%mod
        
        
        #print(hsh)
            
        
        l=int(0)
        i=int(0)
        while i<n:
            while i-l+1 > m:
                l+=1
                
            
            if i-l+1==m:
                total= hsh[i]
                lef=0
                if l-1>=0:
                    lef=hsh[l-1]
                curhsh=(total-lef+mod)%mod
                curbase=pow(p,l,mod)
                inv= pow(curbase,mod-2,mod)
                curhsh=(curhsh*inv)%mod
                if curhsh == hshval:
                    return True;
                
            i+=1
            
            
                
            
            
        return False