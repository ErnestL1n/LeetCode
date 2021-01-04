func singleNumber(nums []int) int {
    a:=0
    for _,n:=range(nums){
        a^=n
    }
    return a
}