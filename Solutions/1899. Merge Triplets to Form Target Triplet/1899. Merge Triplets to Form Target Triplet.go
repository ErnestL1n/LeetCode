func mergeTriplets(triplets [][]int, target []int) bool {
    a,b,c:=0,0,0
    for _,t:=range(triplets){
        if t[0]<=target[0] && t[1]<=target[1] && t[2]<=target[2]{
            a,b,c=max(t[0],a),max(t[1],b),max(t[2],c)
        }
        if a==target[0] && b==target[1] && c==target[2]{
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