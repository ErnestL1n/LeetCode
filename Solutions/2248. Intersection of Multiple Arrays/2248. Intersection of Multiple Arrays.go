func intersection(nums [][]int) []int {
    var res []int
    cnt:=make([]int,1001)
    for _,arr:=range(nums){
        for _,n:=range(arr){
            cnt[n]+=1
        }
    }
    for i:=0;i<len(cnt);i+=1{
        if cnt[i]==len(nums){
            res=append(res,i)
        }
    }
    return res
}