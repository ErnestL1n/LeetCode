class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int res=0;
        for(int i=1;i<points.length;++i){
            int[] curr=points[i-1],next=points[i];
            res+=Math.max(Math.abs(curr[0]-next[0]),Math.abs(curr[1]-next[1]));
        }
        return res;
    }
}