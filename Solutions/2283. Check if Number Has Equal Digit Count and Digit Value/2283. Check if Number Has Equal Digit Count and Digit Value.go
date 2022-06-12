func digitCount(num string) bool {
    cnt:=make([]int,10)
    for _,n:=range num{
        cnt[n-'0']+=1
    }
    for i:=0;i<len(num);i+=1{
        if cnt[i]!=int(num[i]-'0'){
            return false
        }
    }
    return true
}