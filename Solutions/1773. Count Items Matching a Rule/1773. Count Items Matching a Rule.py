class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        res,ty=0,0
        if ruleKey=="color":
            ty=1
        elif ruleKey=="name":
            ty=2
        for it in items:
            if it[ty]==ruleValue:
                res+=1
        return res