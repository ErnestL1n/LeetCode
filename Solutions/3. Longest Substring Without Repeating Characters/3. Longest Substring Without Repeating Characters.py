class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m={}
        i,j,res=0,0,0
        while j<len(s):
            if s[j] in m:
                i=max(i,m[s[j]]+1)
            m[s[j]]=j
            res=max(res,j-i+1)
            j+=1
        return res