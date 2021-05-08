class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def foo(c,t,res,path,begin):
            if t<=0:
                if t==0:
                    res.append(path.copy())
                    return
                return
            for i in range(begin,len(c)):
                if i>begin and c[i]==c[i-1]:
                    continue
                path.append(c[i])
                foo(c,t-c[i],res,path,i+1)
                path.pop()
        candidates.sort()
        path,res=[],[]
        foo(candidates,target,res,path,0)
        return res
                    