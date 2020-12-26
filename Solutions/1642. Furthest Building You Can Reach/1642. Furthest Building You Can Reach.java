class Solution {
    public int furthestBuilding(int[] h, int bricks, int ladders) {
        PriorityQueue<Integer> pq=new PriorityQueue<>();  //min heap
        for(int i=0;i<h.length-1;++i){
            int dis=h[i+1]-h[i];
            if(dis>0)
                pq.offer(dis);
            if(pq.size()>ladders)
                bricks-=pq.poll();
            if(bricks<0)
                return i;
        }
        return h.length-1;
    }
}