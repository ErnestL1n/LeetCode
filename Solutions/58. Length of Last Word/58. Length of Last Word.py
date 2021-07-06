class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s+=' '
        tmp=[]
        for i in range(len(s)):
            if len(tmp)>0 and s[i]!=' ':
                tmp.clear()
            while s[i]!=' ':
                tmp.append(s[i])
                i+=1
        return len(tmp) if len(tmp)>0 else 0
                