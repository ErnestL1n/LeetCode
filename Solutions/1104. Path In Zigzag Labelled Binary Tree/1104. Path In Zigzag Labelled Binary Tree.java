class Solution {
    public List<Integer> pathInZigZagTree(int label) {
        var res=new LinkedList<Integer>();
        int level=0;
        while(1<<level<=label)
            ++level;
        while(label!=0){
            res.addFirst(label);
            label=((1<<level)-1+(1<<(level-1))-label)/2;
            --level;
        }
        return res;
    }
}