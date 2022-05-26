func minMovesToSeat(seats []int, students []int) int {
    sort.Ints(seats)
    sort.Ints(students)
    res:=0
    for i:=0;i<len(seats);i+=1{
        res+=abs(seats[i]-students[i])
    }
    return res
}

func abs(i int) int {
    if i<0{
        return -i
    }
    return i
}
