func largestGoodInteger(num string) string {
    res:=-1
    for i:=2;i<len(num);i+=1{
        if num[i-2]==num[i] && num[i-1]==num[i]{
            res=max(res,int(num[i]-'0'))
        }
    }
    if res==-1{
        return ""
    }
    return string(res+'0')+string(res+'0')+string(res+'0')
}

func max (i,j int) int{
    if i>j{
        return i
    }
    return j
}