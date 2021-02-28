func countMatches(items [][]string, ruleKey string, ruleValue string) int {
    ty,res:=0,0
    if ruleKey=="color"{
        ty=1
    }else if ruleKey=="name"{
        ty=2
    }
    for _,it:=range(items){
        if it[ty]==ruleValue{
            res+=1
        }
    }
    return res
}