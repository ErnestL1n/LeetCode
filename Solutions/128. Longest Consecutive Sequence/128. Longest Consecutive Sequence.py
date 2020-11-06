#HashSet implementation
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums=set(nums)
        best=0
        for x in nums:
            if x-1 not in nums:
                y=x+1
                while y in nums:
                    y+=1
                best=max(best,y-x)
        return best
        
        
#Sort
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums.sort()
        longseq,currseq=1,1
        for i in range(1,len(nums)):
            if nums[i]!=nums[i-1]:
                if nums[i]==nums[i-1]+1:
                    currseq+=1
                else:
                    longseq=max(longseq,currseq)
                    currseq=1
        return max(longseq,currseq)
 
 
#Union Find
class Solution:
    def find(self,ds:List[int],i:int)->int:
        return i if ds[i]<0 else self.find(ds,ds[i])
    def longestConsecutive(self, nums: List[int]) -> int:
        seq=0
        if len(nums)==0:
            return 0
        d={}
        ds=[-1]*len(nums)
        for i in range(len(nums)):
            n=nums[i]
            if n in d:
                continue
            d[n]=i
            if n-1 in d:
                j=self.find(ds,d[n])
                k=self.find(ds,d[n-1])
                ds[j]+=ds[k]
                ds[k]=j
            if n+1 in d:
                j=self.find(ds,d[n])
                k=self.find(ds,d[n+1])
                ds[j]+=ds[k]
                ds[k]=j
            seq=max(seq,abs(ds[self.find(ds,d[n])]))
        return seq