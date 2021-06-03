func findDuplicates(nums []int) []int {
    cnt:=make([]int,len(nums)+1)
    var res []int
    for _,n:=range(nums){
        cnt[n]+=1
    }
    for i:=1;i<=len(nums);i+=1{
        if cnt[i]==2{
            res=append(res,i)
        }
    }
    return res
}