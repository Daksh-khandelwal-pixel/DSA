// Linked List Cycle II (Find the starting node of the cycle)

package LinkedList.Problems;

public class DetectCycleStart {

    // =======================================================
    //   👇 YOUR LEETCODE IMPLEMENTATION GOES HERE 👇
    // =======================================================

    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        int length = 0;

        // 1. Detect if a cycle exists
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            
            // They met! A cycle exists.
            if (fast == slow) {
                ListNode temp = slow;
                
                // Calculate the length of the cycle
                do {
                    temp = temp.next;
                    length++;
                } while (temp != slow);
                
                // BREAK out of the loop so we can move to phase 2
                break; 
            }
        }

        // If we finished the loop and length is still 0, there is no cycle
        if (length == 0) {
            return null;
        }

        // 2. Find start node using the "Head Start" trick
        ListNode fst = head;
        ListNode snd = head;

        // Give 'snd' a head start equal to the length of the cycle
        while (length > 0) {
            snd = snd.next;
            length--;
        }

        // Keep moving both forward 1 step at a time until they collide
        while (fst != snd) {
            fst = fst.next;
            snd = snd.next;
        }

        // They meet exactly at the cycle's starting node!
        return fst;
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

    // Helper method to create lists WITH a cycle for testing
    public static ListNode createListWithCycle(int pos, int... values) {
        if (values.length == 0) return null;
        ListNode head = new ListNode(values[0]);
        ListNode current = head;
        
        ListNode cycleNode = (pos == 0) ? head : null;

        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
            if (i == pos) {
                cycleNode = current;
            }
        }
        
        if (cycleNode != null) {
            current.next = cycleNode;
        }
        return head;
    }

    public static void main(String[] args) {
        DetectCycleStart solution = new DetectCycleStart();

        // Test Case 1: Cycle starts at node with value 2 (index 1)
        // 3 -> 2 -> 0 -> -4 -+
        //      ^             |
        //      +-------------+
        ListNode list1 = createListWithCycle(1, 3, 2, 0, -4);
        ListNode result1 = solution.detectCycle(list1);
        System.out.println("Test Case 1: Expected cycle start value: 2 | Actual: " + (result1 != null ? result1.val : "null"));

        // Test Case 2: Cycle starts at node with value 1 (index 0)
        // 1 -> 2 -+
        // ^       |
        // +-------+
        ListNode list2 = createListWithCycle(0, 1, 2);
        ListNode result2 = solution.detectCycle(list2);
        System.out.println("Test Case 2: Expected cycle start value: 1 | Actual: " + (result2 != null ? result2.val : "null"));

        // Test Case 3: No cycle
        ListNode list3 = createListWithCycle(-1, 1, 2, 3, 4);
        ListNode result3 = solution.detectCycle(list3);
        System.out.println("Test Case 3: Expected cycle start value: null | Actual: " + (result3 != null ? result3.val : "null"));
    }
}
