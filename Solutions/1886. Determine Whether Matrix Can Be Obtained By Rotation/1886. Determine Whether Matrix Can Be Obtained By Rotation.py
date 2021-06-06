class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n=len(mat)
        c=[True]*4
        for i in range(n):
            for j in range(n):
                if mat[i][j]!=target[i][j]:
                    c[0]=False
                if mat[i][j]!=target[j][n-1-i]:
                    c[1]=False
                if mat[i][j]!=target[n-1-j][i]:
                    c[2]=False
                if mat[i][j]!=target[n-1-i][n-1-j]:
                    c[3]=False
        return c[0] or c[1] or c[2] or c[3]