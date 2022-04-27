func find(ds *[]int,i int) int {
    if (*ds)[i]<0 {
        return i
    }
    (*ds)[i]=find(ds,(*ds)[i])
    return (*ds)[i]
}

func smallestStringWithSwaps(s string, pairs [][]int) string {
    m:=make([][]int,len(s))
    ds:=make([]int,len(s))
    for i:=0;i<len(s);i+=1{
        ds[i]=-1
    }
    for _,p:=range pairs{
        i,j:=find(&ds,p[0]),find(&ds,p[1])
        if i!=j{
            ds[i]+=ds[j]
            ds[j]=i
        }
    }
    for i:=0;i<len(s);i+=1{
        m[find(&ds,i)]=append(m[find(&ds,i)],i)
    }
    res:=[]byte(s)
    for _,ids:=range m{
        var ss []byte
        for _,id:=range ids{
            ss=append(ss,res[id])
        }
        sort.Slice(res,func(i,j int)bool{return res[i]<res[j]})
        for i:=0;i<len(ids);i+=1{
            res[ids[i]]=ss[i]
        }
    }
    return string(res)
}