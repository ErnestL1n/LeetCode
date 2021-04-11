func balancedStringSplit(s string) int {
    res,lcnt,rcnt:=0,0,0
    for _,c:=range(s){
        if c=='R'{
            rcnt+=1
        }else{
            lcnt+=1
        }
        if rcnt!=0 && rcnt==lcnt{
            res+=1
        }
    }
    return res
}

func balancedStringSplit(s string) int {
    res,cnt:=0,0
    for _,c:=range(s){
        if c=='L'{
            cnt+=1
        }else{
            cnt-=1
        }
        if cnt==0{
            res+=1
        }
    }
    return res
}