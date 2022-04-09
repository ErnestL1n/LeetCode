func topKFrequent(nums []int, k int) []int {
    um:=make(map[int]int)
    for _,n:=range nums{
        um[n]+=1
    }
    buckets:=make([][]int,len(nums)+1)
    for k,v:=range um{
        buckets[v]=append(buckets[v],k)
    }
    var res []int
    for i:=len(nums);i>=0 && len(res)<k;i-=1{
        if len(buckets[i])>0{
            for _,c:=range buckets[i]{
                res=append(res,c)
            }
        }
    }
    return res
}
