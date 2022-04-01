func divideArray(nums []int) bool {
    m:=make(map[int]int)
    for _,n:=range nums{
        m[n]+=1
    }
    for _,v:=range m{
        if v%2!=0{
            return false
        }
    }
    return true
}