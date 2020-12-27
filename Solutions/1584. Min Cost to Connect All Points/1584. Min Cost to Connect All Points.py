#Prim's with min heap implementation 
class Solution:
    def minCostConnectPoints(self, p: List[List[int]]) -> int:
        res,n,i,connected,pq=0,len(p),0,1,[]
        visited=[False]*n
        while connected<n:
            visited[i],val=True,0
            for j in range(1,n):
                heappush(pq,(abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]),j))
            while visited[pq[0][1]]:
                heappop(pq)
            val,i=heappop(pq)
            res+=val
            connected+=1
        return res
        
        
        
        
        
        
#Kruskal  ,min heap implementation(fetch from back,compare to min priority queue fetch from top())
class Solution:
    def minCostConnectPoints(self, p: List[List[int]]) -> int:
        manhattan=lambda p1,p2:abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
        def find(ds,i:int)->int:
                if ds[i]<0:
                    return i
                ds[i]=find(ds,ds[i])
                return ds[i]
        n,res=len(p),0
        ds,pq=[-1]*n,[]
        for i in range(n):
            for j in range(i+1,n):
                d = manhattan(p[i], p[j])
                pq.append((d,i,j))
        heapify(pq)
        #print(pq)
        while(pq):
            val,i,j=heappop(pq)
            i,j=find(ds,i),find(ds,j)
            if i !=j:
                res+=val
                ds[i]+=ds[j]
                ds[j]=i
                if ds[i]==-n:
                    break
        return res      



#optimal Prim's for Complete Graph (even not faster than above in python,it is ideally optimal)
class Solution:
    def minCostConnectPoints(self, p: List[List[int]]) -> int:
        manhattan=lambda p1,p2:abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
        res,n,i,connected=0,len(p),0,1
        min_d=[4000000]*n
        while connected<n:
            min_d[i]=sys.maxsize
            min_j=i
            for j in range(n):
                if min_d[j]!=sys.maxsize:
                    min_d[j]=min(min_d[j],manhattan(p[i],p[j]))
                    min_j=j if min_d[j]<min_d[min_j] else min_j
            res+=min_d[min_j]
            i=min_j
            connected+=1
        return res
        
