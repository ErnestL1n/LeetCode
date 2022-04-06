func threeSumMulti(arr []int, target int) int {
    m:=make(map[int]int)
    for _,a:=range(arr){
        m[a]+=1
    }
    res:=0
    for k1,_:=range(m){
        for k2,_:=range(m){
            i,j:=k1,k2
            k:=target-i-j
            if _,ok:=m[k];!ok{
                continue
            }
            if i==j && j==k{
                res+=m[i]*(m[i]-1)*(m[j]-2)/6
            }else if i==j && j!=k{
                res+=m[i]*(m[i]-1)*(m[k])/2
            }else if i<j && j<k{
                res+=m[i]*m[j]*m[k]
            }
        }
    }
    mod:=1e9+7
    return res%int(mod)
}