package LinkedList.Problems;
public class RemoveDuplicates {

    // =======================================================
    //   👇 YOUR LEETCODE IMPLEMENTATION GOES HERE 👇
    // =======================================================

    public ListNode deleteDuplicates(ListNode head) {
        ListNode node = head;
        
        while (node != null && node.next != null) {
            if (node.val == node.next.val) {
                node.next = node.next.next;
            } else {
                node = node.next;
            }
        }
        
        return head;
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

    // NEW: Helper method for much cleaner test case syntax
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
        
        // Look how much simpler this syntax is now!
        ListNode head = createList(1, 1, 2, 3, 3);

        // Runs your LeetCode method
        head = new RemoveDuplicates().deleteDuplicates(head);

        // Prints the result
        while (head != null) {
            System.out.print(head.val + " -> ");
            head = head.next;
        }
        System.out.print("null\n");
    }
}