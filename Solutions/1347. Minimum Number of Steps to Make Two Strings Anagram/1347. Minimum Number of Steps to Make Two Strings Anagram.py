class Solution:
    def minSteps(self, s: str, t: str) -> int:
        res,cnt=0,[0]*26
        for c in s:
            cnt[ord(c)-ord('a')]+=1
        for c in t:
            cnt[ord(c)-ord('a')]-=1
        for i in range(26):
            x=0 if cnt[i]==0 else abs(cnt[i])
            res+=x
        return res//2