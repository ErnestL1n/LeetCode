class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        cnt=[0]*51
        for r in ranges:
            for x in range(r[0],r[1]+1):
                cnt[x]=1
        for i in range(left,right+1):
            if cnt[i]==0:
                return False
        return True