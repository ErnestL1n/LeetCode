class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int[] res=new int[tasks.length];
        // [time,weight,index]
        PriorityQueue<int[]> usedServers=new PriorityQueue<>((a,b)->(a[0]!=b[0])?(a[0]-b[0]):(a[1]!=b[1])?a[1]-b[1]:a[2]-b[2]);
        // [weight,index,time]
        PriorityQueue<int[]> freeServers=new PriorityQueue<>((a,b)->(a[0]!=b[0])?(a[0]-b[0]):(a[1]!=b[1])?a[1]-b[1]:a[2]-b[2]);
        for(int i=0;i<servers.length;++i)
            freeServers.add(new int[]{servers[i],i,0});
        for(int i=0;i<tasks.length;++i){
            int t=tasks[i];
            while(usedServers.size()>0 && usedServers.peek()[0]<=i){
                var curr=usedServers.poll();
                freeServers.add(new int[]{curr[1],curr[2],curr[0]});
            }
            if(freeServers.isEmpty()){
                var curr=usedServers.poll();
                res[i]=curr[2];
                curr[0]+=t;
                usedServers.add(curr);
            }else{
                var curr=freeServers.poll();
                res[i]=curr[1];
                curr[2]=i+t;
                usedServers.add(new int[]{curr[2],curr[0],curr[1]});
            }
        }
        return res;
    }
}