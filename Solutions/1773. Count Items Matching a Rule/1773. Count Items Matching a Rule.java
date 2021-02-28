class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int res=0,type=0;
        if(ruleKey.equals("color"))
            type=1;
        else if(ruleKey.equals("name"))
            type=2;
        for(var it:items)
            if(it.get(type).equals(ruleValue))
                ++res;
        return res;
    }
}