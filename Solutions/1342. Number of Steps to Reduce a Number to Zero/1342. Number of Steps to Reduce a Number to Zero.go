func numberOfSteps(num int) int {
    if num==0{
        return 0
    }
    res:=0
    for num>0{
        if num&1!=0{
            res+=2
        }else{
            res+=1
        }
        num>>=1
    }
    return res-1
}