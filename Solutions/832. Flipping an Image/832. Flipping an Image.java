/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.832
public class Flipping_an_Image {

	/**
	 * @param args
	 */
	public static int[][] flipAndInvertImage(int[][] A){
		for(int[] rows:A) {
			reverse(rows);
			invert(rows);
		}
		return A;
	}
	public static void reverse(int[] rows) {
		int l=0,r=rows.length-1;
		while(l<r) {
			int temp=rows[l];
			rows[l]=rows[r];
			rows[r]=temp;
			++l;
			--r;
		}
	}
	public static void invert(int[] rows) {
		int size=0;
        while(size !=rows.length){
            if(rows[size] == 1) rows[size] = 0;
            else rows[size] = 1;
            ++size;
        }
	}
	public static void main(String[] args) {
		int[][] matrix=new int[][] {{0,0,0}, {0,1,0}, {1,1,1}};
		System.out.println("Input image is :");
		for(int i=0;i<matrix.length-1;i++)
			System.out.println(Arrays.toString(matrix[i])+",");
		System.out.print(Arrays.toString(matrix[matrix.length-1]));
		int[][] Flipping_an_Image=flipAndInvertImage(matrix);
		System.out.println();
		System.out.println("Image becomes  :");
		for(int i=0;i<Flipping_an_Image.length-1;i++)
			System.out.println(Arrays.toString(Flipping_an_Image[i])+",");
		System.out.print(Arrays.toString(Flipping_an_Image[Flipping_an_Image.length-1]));
		}

	}



