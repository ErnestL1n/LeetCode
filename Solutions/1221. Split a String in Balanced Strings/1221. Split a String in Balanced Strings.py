class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res,lcnt,rcnt=0,0,0
        for c in s:
            if c=='R':
                rcnt+=1
            else:
                lcnt+=1
            if rcnt!=0 and rcnt==lcnt:
                res+=1
        return res

class Solution:
    def balancedStringSplit(self, s: str) -> int:
        res,cnt=0,0
        for c in s:
            if c=='L':
                cnt+=1
            else:
                cnt-=1
            if cnt==0:
                res+=1
        return res