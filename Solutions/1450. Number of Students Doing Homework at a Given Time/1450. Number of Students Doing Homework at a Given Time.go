func busyStudent(startTime []int, endTime []int, queryTime int) int {
    cnt:=0
    for i:=0;i<len(startTime);i+=1{
        if endTime[i]>=queryTime && startTime[i]<=queryTime{
            cnt+=1
        }
    }
    return cnt
}