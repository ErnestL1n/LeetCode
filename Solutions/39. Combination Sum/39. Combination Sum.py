class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def foo(c,t,path,res,begin):
            if t<=0:
                if t==0:
                    res.append(path.copy())
                    return 
                return
            for i in range(begin,len(c)):
                path.append(c[i])
                foo(c,t-c[i],path,res,i)
                path.pop()
        path,res=[],[]
        foo(candidates,target,path,res,0)  
        return res