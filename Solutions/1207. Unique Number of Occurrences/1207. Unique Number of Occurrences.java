class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        var m=new HashMap<Integer,Integer>();
        for(int a:arr)
            m.put(a,1+m.getOrDefault(a,0));
        return m.size()==new HashSet<Integer>(m.values()).size();
    }
}