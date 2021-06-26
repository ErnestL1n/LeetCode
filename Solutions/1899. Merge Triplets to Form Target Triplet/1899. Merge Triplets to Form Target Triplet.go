func mergeTriplets(triplets [][]int, target []int) bool {
    res:=make([]int,3)
    for _,t:=range(triplets){
        if t[0]<=target[0] && t[1]<=target[1] && t[2]<=target[2]{
            a,b,c:=max(t[0],res[0]),max(t[1],res[1]),max(t[2],res[2])
            res[0],res[1],res[2]=a,b,c
        }
        if res==target{
            return true
        }
    }
    return false
}
func max(i,j int)int{
    if i>j{
        return i
    }
    return j
}