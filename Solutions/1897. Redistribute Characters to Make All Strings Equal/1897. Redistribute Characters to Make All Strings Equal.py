class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        cnt=[0]*26
        for w in words:
            for c in w:
                cnt[ord(c)-ord('a')]+=1
        for x in cnt:
            if x%len(words)!=0:
                return False
        return True
                