
func encode(sessions *[]int ,pos int) string{
    copys:=make([]int,len(*sessions))
    copy(copys,*sessions)
    sort.Ints(copys)
    key:=strconv.Itoa(pos)+"$"
    fmt.Printf(key)
    for i:=0;i<len(copys);i+=1{
        key+=strconv.Itoa(copys[i])+"$"
    }
    return key
}

func solve(um map[string]int,sessions,tasks []int, n,sessionTime,pos int) int {
    if pos>=n{
        return 0
    }
    key:=encode(&sessions,pos)
    if val,ok:=um[key];ok{
        return val
    }
    sessions=append(sessions,tasks[pos])
    res:=1+solve(um,sessions,tasks,n,sessionTime,pos+1)
    sessions=sessions[:len(sessions)-1]
    for i:=0;i<len(sessions);i+=1{
        if sessions[i]+tasks[pos]<=sessionTime{
            sessions[i]+=tasks[pos]
            res=min(res,solve(um,sessions,tasks,n,sessionTime,pos+1))
            sessions[i]-=tasks[pos]
        }
    }
    um[key]=res
    return res
}

func min(i,j int)int{
    if i<j{
        return i
    }
    return j
}

func minSessions(tasks []int, sessionTime int) int {
    var sessions []int
    var um=make(map[string]int)
    return solve(um,sessions,tasks,len(tasks),sessionTime,0)
}