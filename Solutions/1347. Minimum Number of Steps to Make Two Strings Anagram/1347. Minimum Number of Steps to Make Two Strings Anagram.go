func minSteps(s string, t string) int {
    res,cnt:=0,make([]int,26)
    for _,c:=range(s){
        cnt[c-'a']+=1
    }
    for _,c:=range(t){
        cnt[c-'a']-=1
    }
    for i:=0;i<26;i+=1{
        if(cnt[i]==0){
            res+=0
        }else{
            res+=abs(cnt[i])
        }
    }
    return res/2
}
func abs(x int)int{
    if(x<0){
        return -x
    }
    return x
}