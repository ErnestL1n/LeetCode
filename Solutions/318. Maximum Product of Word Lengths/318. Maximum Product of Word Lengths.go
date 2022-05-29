func maxProduct(words []string) int {
    n:=len(words)
    value:=make([]int,n)
    for i:=0;i<n;i+=1{
        tmp:=words[i]
        for j:=0;j<len(tmp);j+=1{
            value[i]|=1<<(tmp[j]-'a')
        }
    }
    res:=0
    for i:=0;i<n;i+=1{
        for j:=i+1;j<n;j+=1{
            if (value[i]&value[j])==0 && (len(words[i])*len(words[j])>res){
                res=len(words[i])*len(words[j])
            }
        }
    }
    return res
}
