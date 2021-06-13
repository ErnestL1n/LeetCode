func isCovered(ranges [][]int, left int, right int) bool {
    cnt:=make([]int,51)
    for _,r:=range(ranges){
        for x:=r[0];x<=r[1];x+=1{
            cnt[x]=1
        }
    }
    for i:=left;i<=right;i+=1{
        if cnt[i]==0{
            return false
        }
    }
    return true
}