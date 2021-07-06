class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s+=' '
        tmp,i="",0
        while i<len(s):
            if len(tmp)>0 and s[i]!=' ':
                print(tmp)
                tmp=""
            while s[i]!=' ':
                tmp+=s[i]
                i+=1
            i+=1
        return len(tmp) if len(tmp)>0 else 0
                