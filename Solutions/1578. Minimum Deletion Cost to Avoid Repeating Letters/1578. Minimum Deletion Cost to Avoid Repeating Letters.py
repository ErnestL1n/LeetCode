class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        maxcost,res=0,0
        for i in range(len(s)):
            if i>0 and s[i]!=s[i-1]:
                maxcost=0
            res+=min(maxcost,cost[i])
            maxcost=max(maxcost,cost[i])
        return res