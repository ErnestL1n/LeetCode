// O(NlogN)
func maxOperations(nums []int, k int) int {
    sort.Ints(nums)
    res:=0
    i,j:=0,len(nums)-1
    for i<j{
        if nums[i]+nums[j]==k{
            res,i,j=res+1,i+1,j-1
        }else if nums[i]+nums[j]>k{
            j-=1
        }else{
            i+=1
        }
    }
    return res
}

// O(N)
func maxOperations(nums []int, k int) int {
    um:=make(map[int]int)
    for _,n:=range nums{
        um[n]+=1
    }
    res:=0
    for n,cnt:=range um{
        if k-n==n{
            res+=cnt/2
        }else if val,ok:=um[k-n];ok{
            tmp:=min(cnt,val)
            res+=tmp
            um[n]-=tmp
            um[k-n]-=tmp
        }
    }
    return res
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}