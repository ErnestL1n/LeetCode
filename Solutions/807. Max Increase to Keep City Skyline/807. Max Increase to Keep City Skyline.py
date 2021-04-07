class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        m,n,res=len(grid),len(grid[0]),0
        skh,skv=[0]*m,[0]*n
        for i in range(m):
            for j in range(n):
                skh[i]=max(skh[i],grid[i][j])
                skv[j]=max(skv[j],grid[i][j])
        for i in range(m):
            for j in range(n):
                res+=min(skh[i],skv[j])-grid[i][j]
        return res