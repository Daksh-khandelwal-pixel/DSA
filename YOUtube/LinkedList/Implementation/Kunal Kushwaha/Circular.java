public class Circular {   
    
    private Node head;
    private Node tail;
    private int size;

    // Node
    private class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }

    public Circular() {
        head = null;
        tail = null;
        size = 0;
    }

    // Insert at the beginning
    public void insertFirst(int value) {
        Node newnode = new Node(value);
        
        if (head == null) {
            head = newnode;
            tail = newnode;
            newnode.next = newnode; // Make it point to itself to be circular
        } else {
            newnode.next = head;
            tail.next = newnode; // Tail must point to the new head
            head = newnode;      // Update head
        }
        size++;
    }

    // Delete a specific value
    public void delete(int value) {
        if (head == null) {
            return;
        }

        // Case 1: Deleting the head node
        if (head.value == value) {
            if (head == tail) { // If it's the only node in the list
                head = null;
                tail = null;
            } else {
                head = head.next;
                tail.next = head;
            }
            size--;
            return;
        }

        // Case 2: Deleting a node in the middle or at the tail
        Node node = head;
        do {
            Node n = node.next;
            if (n.value == value) {
                node.next = n.next; // Bypass the deleted node
                
                // If we deleted the tail, we must update the tail pointer
                if (n == tail) {
                    tail = node;
                }
                
                size--;
                break; // Exit the loop since we found and deleted the value
            }
            node = node.next; // Move forward
        } while (node != head);
    }

    // Display the list
    public void display() {
        Node temp = head;
        if (head != null) {
            do {
                System.out.print(temp.value + " -> ");
                temp = temp.next;
            } while (temp != head);
        }
        System.out.println("HEAD");
    }

    public static void main(String[] args) {

        Circular list = new Circular();

        list.insertFirst(40);
        list.insertFirst(60);
        list.insertFirst(610);
        
        System.out.println("List after insertions:");
        list.display(); // Should print: 610 -> 60 -> 40 -> HEAD

        System.out.println("\nDeleting 60 (Middle):");
        list.delete(60);
        list.display(); // Should print: 610 -> 40 -> HEAD

        System.out.println("\nDeleting 40 (Tail):");
        list.delete(40);
        list.display(); // Should print: 610 -> HEAD
        
        System.out.println("\nDeleting 610 (Head & Only element):");
        list.delete(610);
        list.display(); // Should print: HEAD
    }
}