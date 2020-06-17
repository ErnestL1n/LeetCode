/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1450
public class Number_of_Students_Doing_Homework_at_a_Given_Time {
	/**
	 * @param args
	 */
	 public static int busyStudent(int[] startTime, int[] endTime, int queryTime) {
	        int count=0;
	        for(int i=0;i<startTime.length;i++)
	            if(endTime[i]>=queryTime&&startTime[i]<=queryTime)count++;
	        return count;
	    }
	public static void main(String[] args) {
		int[] startTime=new int[]{1,2,3};
		int[] endTime=new int[] {3,2,7};
		int queryTime=4;
		System.out.println("Given startTime array:"+Arrays.toString(startTime)+ ", endTime array:"+Arrays.toString(endTime)+ " ,queryTime: "+queryTime);
		System.out.println("Number of busy students is "+busyStudent(startTime,endTime,queryTime));
	}
}