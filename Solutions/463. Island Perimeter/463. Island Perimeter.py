class Solution:
    def islandPerimeter(self, g: List[List[int]]) -> int:
        res=0
        for i in range(len(g)):
            for j in range(len(g[0])):
                if g[i][j]==1:
                    res+=4
                    if i>0 and g[i-1][j]==1:
                        res-=2
                    if j>0 and g[i][j-1]==1:
                        res-=2
        return res