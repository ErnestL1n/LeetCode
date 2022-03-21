func partitionLabels(s string) []int {
    last_idx:=make(map[int]int)
    for i,c:=range(s){
        last_idx[(int)(c-'a')]=i
    }
    var res []int
    st,ed:=0,0
    for i,c:=range(s){
        ed=max(ed,last_idx[(int)(c-'a')])
        if ed==i{
            res=append(res,ed-st+1)
            st=ed+1
        }
    }
    return res
}

func max(i,j int)int{
    if i>j{
        return i
    }
    return j
}