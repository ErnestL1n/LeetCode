class Solution {
    public int[] countPoints(int[][] points, int[][] q) {
        int[] res=new int[q.length];
        for(int i=0;i<q.length;++i){
            int cnt=0,rr=q[i][2]*q[i][2];
            for(var p:points){
                boolean check=(q[i][0]-p[0])*(q[i][0]-p[0])+(q[i][1]-p[1])*(q[i][1]-p[1])<=rr;
                if(check)
                    ++cnt;
            }
            res[i]=cnt;
        }
        return res;
    }
}