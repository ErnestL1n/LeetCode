class MapSum {
    private class trie{
        trie[] ch=new trie[26];
        int sum=0;
    }
    private Map<String,Integer> m=new HashMap<>();
    private trie root=new trie(); //here  ,java should build object to become a reference
    /** Initialize your data structure here. */
    public MapSum() {
        
    }
    
    public void insert(String key, int val) {
        var p=root; //here, var like auto ,or :trie p=root is OK
        for(int i=0;i<key.length();++i,p.sum+=val-m.getOrDefault(key,0))
            p=p.ch[key.charAt(i)-'a']=p.ch[key.charAt(i)-'a']==null?new trie():p.ch[key.charAt(i)-'a'];
        m.putIfAbsent(key,val);//here,use m.put(key,val) is OK
    }
    
    public int sum(String prefix) {
        var p=root;
        for(int i=0;i<prefix.length()&&p!=null;p=p.ch[prefix.charAt(i)-'a'],++i);//here,++i should be back,or the fronter statement may skip
        return p==null?0:p.sum;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */