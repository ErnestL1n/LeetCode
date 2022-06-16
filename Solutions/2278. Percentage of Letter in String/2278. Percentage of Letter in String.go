func percentageLetter(s string, letter byte) int {
    cnt:=0
    for _,l:=range s{
        if l==rune(letter){
            cnt+=100
        }
    }
    return cnt/len(s)
}