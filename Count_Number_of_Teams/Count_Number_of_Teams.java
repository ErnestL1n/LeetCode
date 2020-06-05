/**
 * 
 */
package github.com.ErnestL1n;

import java.util.*;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1395
public class Count_Number_of_Teams {

    public static int numTeams(int[] rating) {
	        int count=0;
	        int length=rating.length;
	        for(int j=0;j<length;j++){
	            int leftsmall=0,leftbig=0;
	            int rightsmall=0,rightbig=0;
	            
	            for(int i=0;i<j;i++){            //left
	                if(rating[i]<rating[j])leftsmall++;
	                else if(rating[i]>rating[j])leftbig++;
	            }
	            for(int k=j+1;k<length;k++){     //right
	                if(rating[j]<rating[k])rightbig++;
	                else if(rating[j]>rating[k])rightsmall++;
	            }
	            count+=leftsmall*rightbig+leftbig*rightsmall;
	        }
	        return count;
	    }
	
	public static void main(String[] args) {
		int[] rating1=new int[] {2,5,3,4,1};
		int[] rating2=new int[] {2,1,3};
		int[] rating3=new int[] {1,2,3,4};
		
		System.out.println("Input  1 is:"+Arrays.toString(rating1));
		System.out.println("Output 1 is:"+numTeams(rating1));
		System.out.println("Input  2 is:"+Arrays.toString(rating2));
		System.out.println("Output 2 is:"+numTeams(rating2));
		System.out.println("Input  3 is:"+Arrays.toString(rating3));
		System.out.println("Output 3 is:"+numTeams(rating3));
	}
	

}
