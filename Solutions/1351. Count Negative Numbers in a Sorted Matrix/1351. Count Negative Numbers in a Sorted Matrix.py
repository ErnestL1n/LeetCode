class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res,m,n=0,len(grid),len(grid[0])
        r,c=m-1,0
        while r>=0 and c<n:
            if grid[r][c]<0:
                res+=n-c
                r-=1
            else:
                c+=1
        return res