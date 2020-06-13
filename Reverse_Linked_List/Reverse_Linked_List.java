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
	public static ListNode reverseListRecursive(ListNode head) {
    	if(head == null) return head;
    	ListNode next = head.next;
    	head.next = null;
    	
    	return recursive(head,next);
    }
	private static ListNode recursive(ListNode head, ListNode next){
    	if(next == null)	return head;
    	ListNode temp = next.next;
    	next.next = head;
    	return recursive(next,temp);
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
		System.out.print("Original List is :");
		display(head);
		System.out.println();
		reverseListIterative(head);
		System.out.print("List after Reversing is :");
		display(head);
	}

}
