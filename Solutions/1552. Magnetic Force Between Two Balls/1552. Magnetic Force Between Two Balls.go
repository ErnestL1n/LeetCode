func maxDistance(p []int, m int) int {
    sort.Ints(p)
    lo,hi:=0,p[len(p)-1]-p[0]
    for lo<=hi{
        dis:=(lo+hi)/2
        if foo(p,dis,m){
            lo=dis+1
        }else{
            hi=dis-1
        }
    }
    return hi
}

func foo(pos []int,dis,m int)bool{
    begin,used:=-1,0
    for _,p:=range(pos){
        if begin<=p{
            begin=p+dis
            used+=1
        }
    }
    return used>=m
}