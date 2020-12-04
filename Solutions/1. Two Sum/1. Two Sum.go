func twoSum(nums []int, target int) []int {
    m:=make(map[int]int)
    for v,k:=range(nums){
        if idx,ok:=m[target-k];ok{
            return []int{idx,v}
        }
        m[k]=v
    }
    return nil
}