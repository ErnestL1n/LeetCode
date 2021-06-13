func makeEqual(words []string) bool {
    cnt:=make([]int,26)
    for _,w:=range(words){
        for _,c:=range(w){
            cnt[c-'a']+=1
        }
    }
    for _,x:=range(cnt){
        if x%len(words)!=0{
            return false
        }
    }
    return true
}