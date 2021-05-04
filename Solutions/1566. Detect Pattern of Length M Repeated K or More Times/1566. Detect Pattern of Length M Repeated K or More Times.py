class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        cnt,i=0,0
        while i+m<len(arr):
            if arr[i]!=arr[i+m]:
                cnt=0
            else:
                cnt+=1
            if cnt==(k-1)*m:
                return True
            i+=1
        return False