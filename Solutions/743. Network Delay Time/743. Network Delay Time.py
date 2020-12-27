#Dijkstra
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        vp,visited,d=[],[],[]
        for i in range(N+1):
            vp.append([])
            visited.append(False)
            d.append(sys.maxsize)
        for t in times:
            vp[t[0]].append((t[1],t[2]))
        d[0],d[K]=0,0
        pq=[]
        heapify(pq)
        heappush(pq,(0,K))
        while pq:
            c,u=heappop(pq)
            if visited[u]:
                continue
            for to in vp[u]:
                v,w=to
                if c+w<d[v]:
                    d[v]=c+w
                    heappush(pq,(d[v],v))
            visited[u]=True
        res=max(d)
        return res if res!=sys.maxsize else -1







#Bellman Ford
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        dist=[]
        for i in range(N+1):
            dist.append(0x77777777)
        dist[0]=dist[K]=0
        for i in range(N):
            for _,t in enumerate(times):
                u,v,w=t[0],t[1],t[2]
                if dist[u]!=0x77777777 and dist[v]>dist[u]+w:
                    dist[v]=dist[u]+w
        res=max(dist)
        if res==0x77777777:
            return -1
        return res