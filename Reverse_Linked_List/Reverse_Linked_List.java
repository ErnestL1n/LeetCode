/**
 * 
 */
package github.com.ErnestL1n;

/**
 * @author https://github.com/ErnestL1n
 *
 */
//Leetcode.206
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
public class Reverse_Linked_List {

	/**
	 * @param args
	 */
	
	//Build List with int[] array
	static ListNode head;
	public static ListNode insertNode(ListNode head,int value) {
		ListNode temp=new ListNode();
		temp.value=value;
		temp.next=head;
		head=temp;
		return head;
	}
	public static ListNode Build(int[] values) {
		if(values.length==0)return null;
		//we let head be null initially
		head=null;
        //reversely set in Linked-List 
		for(int i=values.length-1;i>=0;i--)
			head=insertNode(head,values[i]);
		return head;
	}
	//display List
	public static void display(ListNode head) 
	{ 
	    while (head.next != null)  
	    { 
	        System.out.print(head.value + "-> "); 
	        head = head.next; 
	    } 
	    System.out.print(head.value); 
	} 
	
	//The recursive version is slightly trickier and the key is to work backwards. 
	//Assume that the rest of the list had already been reversed,
	//now how do I reverse the front part? Let's assume the list is: n1 ->...-> nk-1 -> nk -> nk+1 -> nm -> null
	//Assume from node nk+1 to nm had been reversed and you are at node nk.
	//n1 ->...-> nk-1 -> nk -> nk+1 ->...-> nm
	//We want nk+1's next node to point to nk.
	//So,
	//nk.next.next = nk;
	//Be very careful that n1's next must point to null. If you forget about this,
	//your linked list has a cycle in it. 
	//This bug could be caught if you test your code with a linked list of size 2.
	
	public static ListNode reverseListRecursive(ListNode head) {
    	if(head == null||head.next==null) return head;
    	ListNode p=reverseListRecursive(head.next);
    	head.next.next=head;
    	head.next=null;
    	return p;
  
	}
	 public static ListNode reverseListIterative(ListNode head) {
	    	if(head == null) return head;
	    	
	    	ListNode next = head.next;
	    	head.next = null;
	        
	    	while(next != null){
	        	ListNode temp = next.next;
	        	next.next = head;
	        	head = next;
	        	next = temp;
	        }
	    	return head;
	    }
	public static void main(String[] args) {
		int[] listValue=new int[] {1,2,3,4,5};
		head=Build(listValue);
		System.out.print("       Original List is :");
		display(head);
		System.out.println();
		ListNode newhead=reverseListRecursive(head);
		System.out.print("List after Reversing is :");
		display(newhead);
	}

}