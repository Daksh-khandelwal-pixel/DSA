// Merge 2 sorted list

package LinkedList.Problems;

public class MergeTwoSortedLists {

    // =======================================================
    //   👇 YOUR LEETCODE IMPLEMENTATION GOES HERE 👇
    // =======================================================

    public ListNode mergeTwoLists(ListNode head1, ListNode head2) {
        
        // 1. Create a fake head to anchor our new list --> New node head which will connect other list
        ListNode dummyHead = new ListNode(-1);
        
        // 2. Create a 'current' pointer that will move down the list
        ListNode current = dummyHead;
        
        // 3. Traverse both lists as long as NEITHER is empty
        while (head1 != null && head2 != null) {
            
            if (head1.val <= head2.val) {
                current.next = head1;   // Hook our train to head1's current car
                head1 = head1.next;     // Slide the head1 pointer forward
            } else {
                current.next = head2;   // Hook our train to head2's current car
                head2 = head2.next;     // Slide the head2 pointer forward
            }
            
            // Move our builder pointer to the newly attached car
            current = current.next; 
        }
        
        // 4. If one list runs out before the other, attach the remaining cars
        if (head1 != null) {
            current.next = head1;
        } else {
            current.next = head2;
        }
        
        // 5. Return the merged list (skipping the fake dummy head)
        return dummyHead.next;
    }

    // =======================================================
    //   👆 YOUR LEETCODE IMPLEMENTATION ENDS HERE 👆
    // =======================================================
    
    
    // ---------------------------------------------------------
    //  IGNORE EVERYTHING BELOW THIS LINE (VS Code Boilerplate)
    // ---------------------------------------------------------

    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) { this.val = val; }
    }

    // Helper method to create lists quickly for testing
    public static ListNode createList(int... values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }
        return head;
    }

    public static void main(String[] args) {
        // Create two sorted test lists
        ListNode list1 = createList(1, 2, 4);
        ListNode list2 = createList(1, 3, 4);

        // Run the method
        ListNode mergedHead = new MergeTwoSortedLists().mergeTwoLists(list1, list2);

        // Print the result
        System.out.print("Merged List: ");
        while (mergedHead != null) {
            System.out.print(mergedHead.val + " -> ");
            mergedHead = mergedHead.next;
        }
        System.out.print("null\n");
    }
}

