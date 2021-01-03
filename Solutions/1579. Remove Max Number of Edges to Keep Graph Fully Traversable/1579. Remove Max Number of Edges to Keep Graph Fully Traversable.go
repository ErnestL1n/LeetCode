func maxNumEdgesToRemove(n int, edges [][]int) int {
    ds_both:=make([]int,n+1)
    for i:=0;i<n+1;i+=1{
        ds_both[i]=-1
    }
    used:=0
    for t:=3;t>=1;t-=1{
        ds_one:=make([]int,n+1)
        copy(ds_one,ds_both)
        var ds []int
        if t==3{
            ds=ds_both
        }else{
            ds=ds_one
        }
        //fmt.Println(ds)
        for _,e:=range(edges){
            if e[0]==t{
                i,j:=find(&ds,e[1]),find(&ds,e[2])
                if i!=j{
                    used+=1
                    ds[i]+=ds[j]
                    ds[j]=i
                }
            }
        }
        if t!=3 && ds[find(&ds,n)]!=-n{
            return -1
        }
    }
    return len(edges)-used
}

func find (ds *[]int,i int)int{
    if (*ds)[i]<0{
        return i
    }
    (*ds)[i]=find(ds,(*ds)[i])
    return (*ds)[i]
}