class Solution:
    def prevPermOpt1(self, arr: List[int]) -> List[int]:
        idx,n=-1,len(arr)
        if n<=1:
            return arr
        for i in range(n-1,0,-1):
            if arr[i-1]>arr[i]:
                idx=i-1
                break
        if idx==-1:
            return arr
        for i in range(n-1,idx,-1):
            if arr[idx]>arr[i] and arr[i]!=arr[i-1]:
                arr[idx],arr[i]=arr[i],arr[idx]
                break
        return arr