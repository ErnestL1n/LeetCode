func rearrangeCharacters(s string, target string) int {
    cnt1,cnt2:=make([]int,26),make([]int,26)
    for _,ch:=range s{
        cnt1[ch-'a']+=1
    }
    for _,ch:=range target{
        cnt2[ch-'a']+=1
    }
    res:=math.MaxInt
    for _,ch:=range target{
        res=min(res,cnt1[ch-'a']/cnt2[ch-'a']);
    }
    return res
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}