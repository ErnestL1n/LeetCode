class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        res,currh=0,0
        cnt=[0]*101
        for h in heights:
            cnt[h]+=1
        for h in heights:
            while cnt[currh]==0:
                currh+=1
            if currh!=h:
                res+=1
            cnt[currh]-=1
        return res