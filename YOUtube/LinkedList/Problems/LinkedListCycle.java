// Linked List Cycle

package LinkedList.Problems;

public class LinkedListCycle {

    // =======================================================
    //   👇 YOUR LEETCODE IMPLEMENTATION GOES HERE 👇
    // =======================================================

    public boolean hasCycle(ListNode head) {
        // 1. Initialize two pointers: fast (hare) and slow (tortoise)
        ListNode fast = head;
        ListNode slow = head;

        // 2. Traverse the list. Fast moves 2 steps, slow moves 1 step.
        // If there's no cycle, the fast pointer will eventually reach null.
        while (fast != null && fast.next != null) {
            fast = fast.next.next; // Move fast pointer 2 steps
            slow = slow.next;      // Move slow pointer 1 step
            
            // 3. If the fast and slow pointers meet, we are trapped in a cycle!
            if (fast == slow) {
                return true;
            }
        }
        
        // 4. If we reach the end of the list (null), there is no cycle.
        return false;
    }

    public int lengthCycle(ListNode head) {
        // 1. Initialize two pointers: fast (hare) and slow (tortoise)
        ListNode fast = head;
        ListNode slow = head;

        // 2. Traverse the list. Fast moves 2 steps, slow moves 1 step.
        // If there's no cycle, the fast pointer will eventually reach null.
        while (fast != null && fast.next != null) {
            fast = fast.next.next; // Move fast pointer 2 steps
            slow = slow.next;      // Move slow pointer 1 step
            
            // 3. If the fast and slow pointers meet, we are trapped in a cycle!
            if (fast == slow) {
                ListNode temp = slow;
                int length = 0;
                do {
                    temp = temp.next;
                    length++;
                } while (temp != slow);
                return length;
            }
        }
        
        return 0;
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
        ListNode(int x) { 
            val = x; 
            next = null;
        }
    }

    // Helper method to create standard straight lists quickly for testing
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

    // Helper method to create lists WITH a cycle for testing
    public static ListNode createListWithCycle(int pos, int... values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        
        // Keep track of the node we want to loop back to
        ListNode cycleNode = (pos == 0) ? head : null;

        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
            if (i == pos) {
                cycleNode = current;
            }
        }
        
        // Connect the tail back to the cycleNode
        if (cycleNode != null) {
            current.next = cycleNode;
        }
        return head;
    }

    public static void main(String[] args) {
        LinkedListCycle solution = new LinkedListCycle();

        // Test Case 1: Has a cycle (tail connects to index 1)
        ListNode cycleList = createListWithCycle(1, 3, 2, 0, -4);
        boolean result1 = solution.hasCycle(cycleList);
        System.out.println("Test Case 1 (Has Cycle)    -> Expected: true  | Actual: " + result1);

        // Test Case 2: Does NOT have a cycle
        ListNode straightList = createList(1, 2, 3, 4, 5);
        boolean result2 = solution.hasCycle(straightList);
        System.out.println("Test Case 2 (No Cycle)     -> Expected: false | Actual: " + result2);
        
        // Test Case 3: Single node without cycle
        ListNode singleNode = createList(1);
        boolean result3 = solution.hasCycle(singleNode);
        System.out.println("Test Case 3 (Single Node)  -> Expected: false | Actual: " + result3);
    }
}