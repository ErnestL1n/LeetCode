class Solution:
    def allPathsSourceTarget(self, g: List[List[int]]) -> List[List[int]]:
        def dfs(g,res,path,node):
            if node==len(g)-1:
                res.append(path[:])
            for i in g[node]:
                path.append(i)
                dfs(g,res,path,i)
                path.pop(-1)
        res,path=[],[]
        path.append(0)
        dfs(g,res,path,0)
        return res