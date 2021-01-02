func flipAndInvertImage(a[][]int) [][]int {
    for _,row:=range(a){
        reverse(&row)
        invert(&row)
    }
    return a
}
func reverse(row *[]int){
    l,r:=0,len(*row)-1
    for l<r{
        (*row)[l],(*row)[r]=(*row)[r],(*row)[l]
        l+=1
        r-=1
    }
}

func invert(row *[]int){
    for i:=0;i<len(*row);i+=1{
        if (*row)[i]==0{
            (*row)[i]=1
        }else{
            (*row)[i]=0
        }
    }
}