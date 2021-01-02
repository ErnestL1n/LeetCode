//buttom up method
func maxCoins(nums []int) int {
    var arr []int
    arr=append(arr,1)
    for _,num:=range(nums){
        if num>0{
            arr=append(arr,num)
        }
    }
    arr=append(arr,1)
    dp:=make([][]int,len(arr))
    for i,_:=range(dp){dp[i]=make([]int,len(arr))}
    for i:=len(arr)-1;i>=0;i-=1{
        for j:=i+1;j<len(arr);j+=1{
            for k:=i+1;k<j;k+=1{
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[j]*arr[k])
            }
        }
    }
    return dp[0][len(arr)-1]
}

func max(i,j int)int{
    if(i>j){
        return i
    }
    return j
}

/*******************************************************************************/
//top down recursive method with memoization

func maxCoins(nums []int) int {
    dp:=make([][]int,502)
    for i:=0;i<502;i+=1{
        dp[i]=make([]int,502)
    }
    var arr []int
    arr=append(arr,1)
    for _,num:=range(nums){
        if num>0{
            arr=append(arr,num)
        }
    }
    arr=append(arr,1)
    return foo(&arr,&dp,0,len(arr)-1)
}

func foo(arr *[]int,dp *[][]int,i,j int)int{
    if j-i<=1{
        return 0
    }
    if (*dp)[i][j]==0{
        for k:=i+1;k<j;k+=1{
            (*dp)[i][j]=max((*dp)[i][j],foo(arr,dp,i,k)+foo(arr,dp,k,j)+(*arr)[i]*(*arr)[j]*(*arr)[k])
        }
    }
    return (*dp)[i][j]
}

func max(i,j int)int{
    if i<j{
        return j
    }
    return i
}