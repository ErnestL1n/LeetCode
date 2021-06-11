class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        lo,hi,res,n=1,10000000,-1,len(dist)
        while lo<=hi:
            mid=(lo+hi)//2
            s=0.0
            for i in range(n-1):
                s+=math.ceil(dist[i]/mid)
            s+=dist[n-1]/mid
            #print(s)
            if s>hour:
                lo=mid+1
            else:
                hi=mid-1
                res=mid
        return res