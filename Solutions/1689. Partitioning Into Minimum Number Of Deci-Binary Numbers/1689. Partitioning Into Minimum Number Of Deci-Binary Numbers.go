func minPartitions(n string) int {
    res:='0'
    for _,c:=range(n){
        if c>res{
            res=c
        }
    }
    return int(res-'0')
}

