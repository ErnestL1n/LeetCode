/**
 * 
 */
package github.com.ErnestL1n;

import java.util.Arrays;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.704
public class Binary_Search {

	/**
	 * @param args
	 */
	//intuitive method:recursive calls
	public static int BinarySearch(int[] nums1,int target) {
		if(nums1.length==0)return -1;
		return recursive(nums1,0,nums1.length-1,target);
	}
	public static int recursive(int[] nums1,int left,int right,int target) {
		if(left==right)return nums1[left]==target?left:-1;
		else {
			int middle=(left+right)/2;
			if(target<=nums1[middle])return recursive(nums1,left,middle,target);
			else return recursive(nums1,middle+1,right,target);
		}
	}
	
	//smarter method
	public static int search(int[] nums2,int target) {
		int left=0,right=nums2.length-1;
		
		while(left<=right) {
			int mid=(left+right)/2;
			if(nums2[mid]==target)return mid;
			else if(target<nums2[mid]) //target is in the left part
				right=mid-1;
			else left=mid+1;
		}
		//non of the above case
		return -1;
	}
	
	public static void main(String[] args) {
		//in ascending order
		int[] nums=new int[] {-1, 0, 3, 5, 9, 12};
		int target=5;
		System.out.println("Input numbers are "+Arrays.toString(nums));
        System.out.println("Target index is (Recursive) "+BinarySearch(nums,target));
        System.out.println("Input numbers are "+Arrays.toString(nums));
        System.out.println("Target index is (Iterative) "+search(nums,target));
        
	}

}
