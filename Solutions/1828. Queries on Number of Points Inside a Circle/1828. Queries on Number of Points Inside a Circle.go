func countPoints(points [][]int, queries [][]int) []int {
    var res []int
    for _,q:=range(queries){
        cnt,rr:=0,q[2]*q[2]
        for _,p:=range(points){
            check:=(q[0]-p[0])*(q[0]-p[0])+(q[1]-p[1])*(q[1]-p[1])<=rr
            if check{
                cnt+=1
            }
        }
        res=append(res,cnt)
    }
    return res
}