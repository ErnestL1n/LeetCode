/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1380
public class Lucky_Numbers_in_a_Matrix {

	/**
	 * @param args
	 */
	public static List<Integer> luckyNumbers (int[][] matrix){
		List<Integer> answer=new ArrayList<>();
        //note:
        //arr.length      //is the first dimension
        //arr[0].length   //is the second dimension
        int[]  rows=new int[matrix.length];
        int[] columns=new int[matrix[0].length];
        //     row to find min=>set max
        Arrays.fill(rows,Integer.MAX_VALUE);
        //  column to find max=>set min
        Arrays.fill(columns,Integer.MIN_VALUE);
        for(int i=0;i<matrix.length;i++)
            for(int j=0;j<matrix[0].length;j++){
                rows[i]=Math.min(rows[i],matrix[i][j]);
                columns[j]=Math.max(columns[j],matrix[i][j]);
            }
        
        for(int i=0;i<matrix.length;i++)
            for(int j=0;j<matrix[0].length;j++){
                if(columns[j]==rows[i])
                    answer.add(rows[i]);
            }
        return answer;    
	}
	
	//another version beats 100% time(0ms) and 84% space 
	//reference:https://leetcode.com/yogeshrawat/
	public static List<Integer> luckyNumbersBest (int[][] matrix){
		List<Integer> answer=new ArrayList<>();
		for(int temp[]:matrix)CountLuckyNumbers(matrix,temp,answer);
		return answer;
	}
	public static void CountLuckyNumbers(int[][]matrix, int[] temp, List<Integer> answer) {
		int minIndex=0;
		int element=Integer.MAX_VALUE;

		//first for loop, finding min in each row
		for( int i =0; i < temp.length; i++ )
		{
		if(element>temp[i]) {
			minIndex=i;
			element=temp[i];
			}
		}


                //second for loop, finding max in each column,if flag==false(not maximum in its column)=>not the lucky number
		boolean flag=true;
		for(int i=0;i<matrix.length;i++) {
			if(element<matrix[i][minIndex]) {
				flag=false;
				break;
			}
		}
		if(flag&&element!=Integer.MAX_VALUE)answer.add(element);
	}
	
	
	
	public static void main(String[] args) {
		int[][] array=new int[][] {{3,7,8}, {9,11,13}, {15,16,17}};
		System.out.println("Input matrix is :");
		for(int i=0;i<array.length-1;i++)
			System.out.println(Arrays.toString(array[i])+",");
		System.out.print(Arrays.toString(array[array.length-1]));
		System.out.println();
		System.out.println("Lucky numbers are "+luckyNumbersBest(array));
		}

	}
