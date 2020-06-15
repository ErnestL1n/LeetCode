/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1266
public class Minimum_Time_Visiting_All_Points {

	/**
	 * @param args
	 */
	public static int minTimeToVisitAllPoints(int[][] points) {
	        int time=0;
	        for(int i=1;i<points.length;i++){
	            int[] next=points[i],curr=points[i-1];
	            //move diagonally [0] for x, [1] for y
	            time+=Math.max(Math.abs(next[0]-curr[0]),Math.abs(next[1]-curr[1]));
	        }
	        return time;
	    }
	public static void main(String[] args) {
		int [][] points=new int[][] {{1,1},{3,4},{-1,0}};
		System.out.print("Points are ");
		for(int[] point:points)System.out.print(Arrays.toString(point)+" ");
		System.out.println();
		System.out.println("Minimum Time Visiting All Points is:"+minTimeToVisitAllPoints(points));

	}

}
