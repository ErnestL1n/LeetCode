class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        cnt=0
        for i in range(len(startTime)):
            if endTime[i]>=queryTime and startTime[i]<=queryTime:
                cnt+=1
        return cnt