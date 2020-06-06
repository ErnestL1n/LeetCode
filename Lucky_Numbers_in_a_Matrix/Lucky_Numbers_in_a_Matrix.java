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
	public static void main(String[] args) {
		int[][] array=new int[][] {{3,7,8}, {9,11,13}, {15,16,17}};
		System.out.println("Input array is :");
		System.out.print("[");
		for(int i=0;i<array.length-1;i++)
			System.out.println(Arrays.toString(array[i])+",");
		System.out.print(Arrays.toString(array[array.length-1]));
		System.out.println("]");
		System.out.println("Lucky numbers are "+luckyNumbers(array));
		}

	}

