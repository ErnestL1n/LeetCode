func maxSatisfaction(s []int) int {
    sort.Ints(s)
    res,total :=0,0
    for i:=len(s)-1;i>=0&&s[i]+total>0;i--{
        total+=s[i]
        res+=total
    }
    return res
}