class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        def find(ds,i)->int:
            if ds[i]<0:
                return i
            ds[i]=find(ds,ds[i])
            return ds[i]
        ds_both,used=[-1]*(n+1),0
        for t in range(3,0,-1):
            ds_one=ds_both[:]
            ds=ds_both if t==3 else ds_one
            for e in edges:
                if e[0]==t:
                    i,j=find(ds,e[1]),find(ds,e[2])
                    if i!=j:
                        used+=1
                        ds[i]+=ds[j]
                        ds[j]=i
            if t!=3 and ds[find(ds,n)]!=-n:
                return -1
                        
        return len(edges)-used                
                    
        
        