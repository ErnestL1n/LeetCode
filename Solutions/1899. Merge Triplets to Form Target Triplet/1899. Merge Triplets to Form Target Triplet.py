class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        a,b,c=0,0,0
        for t in triplets:
            if t[0]<=target[0] and t[1]<=target[1] and t[2]<=target[2]:
                a,b,c=max(t[0],a),max(t[1],b),max(t[2],c)
            if a==target[0] and b==target[1] and c==target[2]:
                return True
        return False