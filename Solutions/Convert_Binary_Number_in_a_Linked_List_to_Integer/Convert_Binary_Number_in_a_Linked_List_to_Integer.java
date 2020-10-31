/**
 * 
 */
package github.com.ErnestL1n;
import java.util.*;
/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.1290

class ListNode{
	int value;
	ListNode next;
	ListNode(){};
	ListNode(int value){this.value=value;};
	ListNode(int value,ListNode next){
		this.value=value;
		this.next=next;
	}
}

public class Convert_Binary_Number_in_a_Linked_List_to_Integer {

	/**
	 * @param args
	 */
	//practice linked-list and StringBuffer class
	//reference:https://leetcode.com/sstufetip/
	public static int getDecimalValue(ListNode head) {
        //Java StringBuffer class is used to create mutable (modifiable) string
        StringBuffer str=new StringBuffer();
        while(head!=null){
            str.append(head.value);
            head=head.next;
        }
        return Integer.parseInt(str.toString(),2);
    }
	
	//Build ListNode is contributed by Princi Singh 
	static ListNode head;
	public static ListNode insertNode(ListNode head,int value) {
		ListNode temp=new ListNode();
		temp.value=value;
		//we let root be null initially
		temp.next=head;
		head=temp;
		return head;
	}
	public static ListNode Build(int[] values) {
		if(values.length==0)return null;
		head=null;
        //reversely set in Linked-List 
		for(int i=values.length-1;i>=0;i--)
			head=insertNode(head,values[i]);
		return head;
	}
	public static void display(ListNode root) 
	{ 
	    while (root.next != null)  
	    { 
	        System.out.print(root.value + "-> "); 
	        root = root.next; 
	    } 
	    System.out.print(root.value); 
	} 
	public static void main(String[] args) {
		int[] listValue=new int[] {1,0,1};
		head=Build(listValue);
		System.out.print("List is :");
		display(head);
		System.out.println();
		System.out.println("Decimal Value of the linked list is :"+getDecimalValue(head)+" (DecimalValue)");
		
	}

}