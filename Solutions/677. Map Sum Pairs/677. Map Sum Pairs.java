public class trie{
    trie[] ch=new trie[26];
    int sum=0;
}
class MapSum {
    private Map<String,Integer> m=new HashMap<>();
    private trie root=new trie(); //here  ,java always builds object to become a reference
    /** Initialize your data structure here. */
    public MapSum() {
        
    }
    
    public void insert(String key, int val) {
        trie p=root; //here, var like auto ,or "trie p=root" is OK
        for(var c:key.toCharArray()){
            if(p.ch[c-'a']!=null){
                p.ch[c-'a']=p.ch[c-'a'];
                p=p.ch[c-'a'];
            }else{
                p.ch[c-'a']=new trie();
                p=p.ch[c-'a'];
            }
            p.sum+=val-m.getOrDefault(key,0);
        }
        m.put(key,val);
    }
    
    public int sum(String prefix) {
        trie p=root;
        for(var c:prefix.toCharArray()){
            if(p==null)
                break;
            p=p.ch[c-'a'];
        }
        return p==null?0:p.sum;
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */