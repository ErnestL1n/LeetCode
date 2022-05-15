func divisorSubstrings(num int, k int) int {
    res,s:=0,strconv.Itoa(num)
    for i:=0;i<=len(s)-k;i+=1{
        sub:=s[i:i+k]
        n,_:=strconv.Atoi(sub)
        if n>0 && num%n==0{
            res+=1
        }
    }
    return res
}