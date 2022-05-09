func letterCombinations(digits string) []string {
    var res []string
    if len(digits)==0{
        return res
    }
    numbers:=[]string{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
    res=append(res,"")
    for i:=0;i<len(digits);i+=1{
        x:=digits[i]-'0'
        for len(res[0])==i{
            t:=res[0];res=res[1:]
            for _,s:=range numbers[x]{
                res=append(res,t+string(s))
            }
        }
    }
    return res
}