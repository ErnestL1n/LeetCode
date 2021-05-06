func lengthOfLongestSubstring(s string) int {
    m:=make(map[string]int)
    res:=0
    for i,j:=0,0;j<len(s);j+=1{
        if pos,ok:=m[string(s[j])];ok{
            i=max(i,pos+1)
        }
        m[string(s[j])]=j
        res=max(res,j-i+1)
    }
    return res
}
func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}