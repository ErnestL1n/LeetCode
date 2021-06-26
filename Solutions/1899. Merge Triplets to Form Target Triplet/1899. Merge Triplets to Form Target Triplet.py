class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        res=[0,0,0]
        for t in triplets:
            if t[0]<=target[0] and t[1]<=target[1] and t[2]<=target[2]:
                res=[max(res[0],t[0]),max(res[1],t[1]),max(res[2],t[2])]
            if res==target:
                return True
        return False