class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        res=[]
        for q in queries:
            cnt,rr=0,q[2]*q[2]
            for p in points:
                check=(q[0]-p[0])*(q[0]-p[0])+(q[1]-p[1])*(q[1]-p[1])<=rr
                if check:
                    cnt+=1
            res.append(cnt)
        return res