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