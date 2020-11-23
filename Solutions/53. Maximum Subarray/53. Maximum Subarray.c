#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

int maxSubArray(int* nums, int numsSize){
    int max_so_far=INT_MIN;
    int max_ending_now=0;
    for(int i=0;i<numsSize;i++){
        max_ending_now+=nums[i];
        if(max_ending_now>max_so_far)
            max_so_far=max_ending_now;
        if(max_ending_now<0)
            max_ending_now=0;
    }
    return max_so_far;
}

