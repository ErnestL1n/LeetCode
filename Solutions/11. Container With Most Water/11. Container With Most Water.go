func maxArea(height []int) int {
    i,j:=0,len(height)-1
    res:=0
    for i<j{
        res=max(res,(j-i)*min(height[i],height[j]))
        if height[i]<height[j]{
            i+=1
        }else{
            j-=1
        }
    }
    return res
}

func max(i,j int) int{
    if i>j{
        return i
    }
    return j
}

func min(i,j int) int{
    if i<j{
        return i
    }
    return j
}