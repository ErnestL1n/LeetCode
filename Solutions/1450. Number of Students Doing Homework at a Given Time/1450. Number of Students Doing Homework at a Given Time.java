class Solution {
    public int busyStudent(int[] startTime, int[] endTime, int queryTime) {
        int cnt=0;
        for(int i=0;i<startTime.length;++i)
            if(endTime[i]>=queryTime && startTime[i]<=queryTime)
                ++cnt;
        return cnt;
    }
}