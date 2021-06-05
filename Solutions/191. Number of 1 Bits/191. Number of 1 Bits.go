func hammingWeight(n uint32) int {
    res:=0
    for n>0{
        t:=n&1
        if t==1{
            res+=1
        }
        n>>=1
    }
    return res
}

func hammingWeight(n uint32) int {
    res:=0
    for n>0{
        res+=1
        n&=(n-1)
    }
    return res
}