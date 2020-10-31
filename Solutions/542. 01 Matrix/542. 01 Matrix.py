#bfs
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        q,m,n=[],len(matrix),len(matrix[0])
        for i in range(m):
            for j in range(n):
                if(matrix[i][j])==0 :
                    q.append((i,j))
                else:
                    matrix[i][j]=0x7fffffff
        for i,j in q:
            for r,c in ((i,j+1),(i,j-1),(i+1,j),(i-1,j)):
                z=matrix[i][j]+1
                if(0<=r<m and 0<=c<n and matrix[r][c]>z):
                    matrix[r][c]=z
                    q.append((r,c))
        return matrix
                

#dp
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m,n=len(matrix),len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]!=0:
                    matrix[i][j]=10000
                    upmin=matrix[i-1][j]+1 if i>0 else m*n # or else matrix[i][j]
                    leftmin=matrix[i][j-1]+1 if j>0 else m*n
                    matrix[i][j]=min(min(upmin,leftmin),matrix[i][j])
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if matrix[i][j]!=0:
                    downmin=matrix[i+1][j]+1 if i<m-1 else m*n
                    rightmin=matrix[i][j+1]+1 if j<n-1 else m*n
                    matrix[i][j]=min(min(downmin,rightmin),matrix[i][j])
        return matrix          