func removeDuplicates(s string, k int) string {
    i,n:=0,len(s)
    cnt:=make([]int,n)
    tmp:=[]rune(s)
    for j:=0;j<n;i,j=i+1,j+1{
        tmp[i]=tmp[j]
        if i>0 && tmp[i-1]==tmp[j]{
            cnt[i]=cnt[i-1]+1
        }else{
            cnt[i]=1
        }
        if cnt[i]==k{
            i-=k
        }
    }
    return string(tmp[:i])
}