class Solution:
    def minCostConnectPoints(self, p: List[List[int]]) -> int:
        n,res,connected,i,pq=len(p),0,1,0,[]
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