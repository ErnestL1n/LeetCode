class Solution:
    def maxDistance(self, p: List[int], m: int) -> int:
        def foo(pos,dis,m):
            begin,used=-1,0
            for p in pos:
                if(begin<=p):
                    used+=1
                    begin=p+dis
            return used>=m
        p.sort()
        lo,hi=0,p[len(p)-1]-p[0]
        while lo<=hi:
            dis=(lo+hi)//2
            if foo(p,dis,m):
                lo=dis+1
            else:
                hi=dis-1
        return hi
