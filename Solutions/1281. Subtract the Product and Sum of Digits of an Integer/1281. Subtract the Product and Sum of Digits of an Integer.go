func subtractProductAndSum(n int) int {
    s,pro:=0,1
    for n>0 {
        tmp:=n%10
        s+=tmp
        pro*=tmp
        n/=10
    }
    return pro-s
}