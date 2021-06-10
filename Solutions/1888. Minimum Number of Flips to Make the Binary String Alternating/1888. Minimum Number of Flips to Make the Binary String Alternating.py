class Solution:
    def minFlips(self, s: str) -> int:
        n,res,cnt1,cnt2,s1,s2=len(s),float('inf'),0,0,"",""
        s+=s
        for i in range(2*n):
            if i%2==0:
                s1+='0'
                s2+='1'
            else:
                s1+='1'
                s2+='0'
        for i in range(2*n):
            if s1[i]!=s[i]:
                cnt1+=1
            if s2[i]!=s[i]:
                cnt2+=1
            if i>=n:
                if s1[i-n]!=s[i-n]:
                    cnt1-=1
                if s2[i-n]!=s[i-n]:
                    cnt2-=1
            if i>=n-1:
                res=min(res,cnt1,cnt2)
        return res

# space and time optimization
class Solution:
    def minFlips(self, s: str) -> int:
        res,cnt1,cnt2,n=float('inf'),0,0,len(s)
        for i in range(2*n):
            c=s[i%n]
            cc='0' if i%2==0 else '1'
            if c!=cc:
                cnt1+=1
            else:
                cnt2+=1
            if i>=n:
                idx=i-n
                cc='0' if idx%2==0 else '1'
                if cc!=s[idx]:
                    cnt1-=1
                else:
                    cnt2-=1
            if i>=n-1:
                res=min(res,cnt1,cnt2)
        return res