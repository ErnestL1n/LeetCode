func minOperations(logs []string) int {
    depth:=0
    for _,log:=range(logs){
        if log=="./"{
            continue
        }else if log=="../"{
            depth-=1
            if depth<0{
                depth=0
            }
        }else{
            depth+=1
        }
    }
    return depth
}