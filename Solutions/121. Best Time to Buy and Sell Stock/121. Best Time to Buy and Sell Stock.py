class Solution:
    def maxProfit(self, p: List[int]) -> int:
        res,minv=0,sys.maxsize
        for i in range(len(p)):
            if minv>p[i]:
                minv=p[i]
            else:
                res=max(res,p[i]-minv)
        return res
        
        

#dp
class Solution:
    def maxProfit(self, p: List[int]) -> int:
        res,n=0,len(p)
        record=[0]*n
        for i in range(1,len(p)):
            record[i]=max(0,record[i-1]+p[i]-p[i-1])
            res=max(res,record[i])
        return res