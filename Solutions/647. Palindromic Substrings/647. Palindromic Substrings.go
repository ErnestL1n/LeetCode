var res int

func countSubstrings(s string) int {
    res=0
    for i:=0;i<len(s);i+=1{
        extendPal(s,i,i)
        extendPal(s,i,i+1)
    }
    return res
}

func extendPal(s string,i,j int){
    for i>=0 && j<len(s) && s[i]==s[j]{
        res,i,j=res+1,i-1,j+1
    }
}