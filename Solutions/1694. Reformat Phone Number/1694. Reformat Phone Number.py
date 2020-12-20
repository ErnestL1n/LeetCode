class Solution:
    def reformatNumber(self, number: str) -> str:
        tmp=""
        for _,c in enumerate(number):
            if c!=' ' and c!='-':
                tmp+=c
        res=""
        i=0
        while i<len(tmp):
            if len(tmp)-i==4:
                res+=tmp[i]
                res+=tmp[i+1]
                i+=2
            elif len(tmp)-i==2:
                res+=tmp[i]
                res+=tmp[i+1]
                break
            elif len(tmp)-i==3:
                res+=tmp[i]
                res+=tmp[i+1]
                res+=tmp[i+2]
                break
            else:
                res+=tmp[i]
                res+=tmp[i+1]
                res+=tmp[i+2]
                i+=3
            res+='-'
        return res