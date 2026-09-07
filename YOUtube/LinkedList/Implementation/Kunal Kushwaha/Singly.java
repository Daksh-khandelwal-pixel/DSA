public class Singly {

    // ============================================================
    // Node = one box/node in our linked list
    // Each node stores:
    // 1. value -> the actual data
    // 2. next  -> reference to the next node
    // ============================================================
    private class Node {

        private int value;
        private Node next;

        // Constructor: create a node with only a value
        public Node(int value) {
            this.value = value;
            this.next = null;
        }

        // Constructor: create a node with a value and next node
        public Node(int value, Node next) {
            this.value = value;
            this.next = next;
        }
    }


    // ============================================================
    // Linked List properties
    // ============================================================

    // head = first node in the linked list
    private Node head;

    // tail = last node in the linked list
    private Node tail;

    // size = number of nodes currently in the list
    private int size;


    // Constructor for LinkedList
    public Singly() {
        head = null;
        tail = null;
        size = 0;
    }


    // ============================================================
    // INSERTION
    // ============================================================

    // ------------------------------------------------------------
    // Insert a new node at the beginning of the list
    // ------------------------------------------------------------
    public void insertAtHead(int value) {

        // Create a new node
        Node newNode = new Node(value);

        // New node points to the current head
        newNode.next = head;

        // New node becomes the new head
        head = newNode;

        // If the list was empty, the new node is also the tail
        if (tail == null) {
            tail = head;
        }

        // One new node has been added
        size++;
    }


    // ------------------------------------------------------------
    // Insert a new node at the end of the list
    // ------------------------------------------------------------
    public void insertAtTail(int value) {

        // If the list is empty, use insertAtHead()
        // because the new node will be BOTH head and tail.
        if (tail == null) {
            insertAtHead(value);
            return;
        }

        // Create a new node
        Node newNode = new Node(value);

        // Current tail points to the new node
        tail.next = newNode;

        // New node becomes the new tail
        tail = newNode;

        // One new node has been added
        size++;
    }


    // ------------------------------------------------------------
    // Insert a new node at a specific index
    //
    // Example:
    //
    // 10 -> 20 -> 30
    //
    // insertAtIndex(25, 2)
    //
    // becomes:
    //
    // 10 -> 20 -> 25 -> 30
    // ------------------------------------------------------------
    public void insertAtIndex(int value, int index) {

        // Index 0 means insert at the beginning
        if (index == 0) {
            insertAtHead(value);
            return;
        }

        // Index equal to size means insert at the end
        if (index == size) {
            insertAtTail(value);
            return;
        }

        // Start from the head --> previous is just a reference to our head and not actually changing head
        Node previous = head;

        // Move to the node immediately BEFORE the desired index
        for (int i = 1; i < index; i++) {
            previous = previous.next; // eg - index 2
        }

        // Create the new node.
        // It should point to the node currently after 'previous'.
        Node newNode = new Node(value, previous.next); // this makes our new node connect to for eg - index 3

        // Make the previous node point to our new node
        previous.next = newNode;

        // One node has been added
        size++;
    }

    // ------------------------------------------------------------
    // Insert using Recursion
    // ------------------------------------------------------------
    public void insertRec(int value,int index){
         head = insertRec(value, index, head);
    }
    private Node insertRec(int value, int index, Node node){
        if(index == 0){
            Node temp = new Node(value,node);
            size++;
            return temp;
        }
        node.next = insertRec(value, index-1, node.next);
        return node;  
    }


    // ============================================================
    // DISPLAY
    // ============================================================

    // Print every node from head to tail
    public void display() {

        Node current = head;

        while (current != null) {

            System.out.print(current.value + " -> ");

            // Move to the next node
            current = current.next;
        }

        System.out.println("END");
    }


    // ============================================================
    // DELETION
    // ============================================================

    // ------------------------------------------------------------
    // Delete the first node
    // ------------------------------------------------------------
    public int deleteFirst() {

        // Store the value we are going to delete
        int deletedValue = head.value;

        // Move head to the second node
        head = head.next;

        // If there is no node left,
        // tail must also become null.
        if (head == null) {
            tail = null;
        }

        // One node has been removed
        size--;

        return deletedValue;
    }


    // ------------------------------------------------------------
    // Delete the last node
    // ------------------------------------------------------------
    public int deleteLast() {

        // If there is only one node,
        // deleting the last node is the same as deleting the first.
        if (size <= 1) {
            return deleteFirst();
        }

        // Find the node immediately before the tail
        Node secondLast = getNode(size - 2);

        // Store the value of the node we are deleting
        int deletedValue = tail.value;

        // Second-last node becomes the new tail
        tail = secondLast;

        // New tail should point to nothing
        tail.next = null;

        // One node has been removed
        size--;

        return deletedValue;
    }


    // ------------------------------------------------------------
    // Delete a node at a specific index
    //
    // Example:
    //
    // 10 -> 20 -> 30 -> 40
    //
    // deleteAtIndex(2)
    //
    // becomes:
    //
    // 10 -> 20 -> 40
    // ------------------------------------------------------------
    public int deleteAtIndex(int index) {

        // If index is 0, delete the head
        if (index == 0) {
            return deleteFirst();
        }

        // If index is the last node, delete the tail
        if (index == size - 1) {
            return deleteLast();
        }

        // Find the node BEFORE the one we want to delete
        Node previous = getNode(index - 1);

        // Store the value we are deleting
        int deletedValue = previous.next.value;

        // Skip over the node being deleted
        //
        // Before:
        //
        // previous -> nodeToDelete -> nextNode
        //
        // After:
        //
        // previous ----------------> nextNode
        previous.next = previous.next.next;

        // One node has been removed
        size--;

        return deletedValue;
    }


    // ============================================================
    // SEARCHING / GETTING NODES
    // ============================================================

    // ------------------------------------------------------------
    // Find the FIRST node containing a particular value
    // ------------------------------------------------------------
    public Node findByValue(int value) {

        Node current = head;

        while (current != null) {

            if (current.value == value) {
                return current;
            }

            current = current.next;
        }

        // Value was not found
        return null;
    }


    // ------------------------------------------------------------
    // Get the node at a specific index
    //
    // Example:
    //
    // 10 -> 20 -> 30
    //          index 1
    //
    // getNode(1) returns the node containing 20.
    // ------------------------------------------------------------
    public Node getNode(int index) {

        Node current = head;

        for (int i = 0; i < index; i++) {
            current = current.next;
        }

        return current;
    }


    // ============================================================
    // MAIN METHOD
    // ============================================================

    public static void main(String[] args) {

        Singly list = new Singly();

        list.insertAtHead(20);
        list.insertAtHead(60);
        list.insertAtHead(2);

        list.insertAtTail(222);

        list.insertAtIndex(50, 2);

        list.display();

        System.out.println(list.deleteFirst());

        list.display();

        System.out.println(list.deleteLast());

        list.display();

        System.out.println(list.deleteAtIndex(2));

        list.display();

        list.insertRec(40, 1);
        list.display(); 
    }
}