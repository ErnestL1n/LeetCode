class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        cnt,n=0,len(arr)
        for i in range(0,n-2):
            for j in range(i+1,n-1):
                if abs(arr[i]-arr[j])<=a:
                    for k in range(j+1,n):
                        if abs(arr[j]-arr[k])<=b and abs(arr[k]-arr[i])<=c:
                            cnt+=1
        return cnt;