class Solution {
    public void foo(List<List<String>> res,List<String> cur,String s,int st){
        if(st==s.length()){
            res.add(new ArrayList(cur));
            return;
        }
        for(int hi=st;hi<s.length();++hi){
            if(isPal(s,st,hi)){
                cur.add(s.substring(st,hi+1));
                foo(res,cur,s,hi+1);
                cur.remove(cur.size()-1);
            }
        }
    }
    public boolean isPal(String s,int st,int ed){
        for(int i=st,j=ed;i<j;++i,--j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
        }
        return true;
    }
    public List<List<String>> partition(String s) {
        List<List<String>> res=new ArrayList();
        List<String> cur=new ArrayList();
        foo(res,cur,s,0);
        return res;
    }
}