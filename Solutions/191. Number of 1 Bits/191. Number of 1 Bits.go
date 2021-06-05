func hammingWeight(n uint32) int {
    res:=0
    for n>0{
        res+=1
        n&=(n-1)
    }
    return res
}