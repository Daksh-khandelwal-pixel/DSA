public class Doubly {

    private Node head;
    private Node tail;
    private int size;

    // Node
    private class Node {
        int value;
        Node next;
        Node previous;

        Node(int value) {
            this.value = value;
        }
    }

    public Doubly() {
        head = null;
        tail = null;
        size = 0;
    }

    // Insert at beginning
    public void insertFirst(int value) {
        Node newNode = new Node(value);

        newNode.next = head;

        if (head != null) {
            head.previous = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
        size++;
    }

    // Insert at end
    public void insertLast(int value) {
        Node newNode = new Node(value);

        if (tail == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.previous = tail;
            tail = newNode;
        }

        size++;
    }

    // Insert at index
    public void insertIndex(int value, int index) {

        if (index == 0) {
            insertFirst(value);
            return;
        }

        if (index == size) {
            insertLast(value);
            return;
        }

        Node temp = head;

        for (int i = 1; i < index; i++) {
            temp= temp.next;
        }

        Node node = new Node(value);

        node.next = temp.next;
        node.previous = temp;

        temp.next.previous = node;
        temp.next = node;

        size++;
    }

    // Delete first node
    public int deleteFirst() {
        if (head == null) {
            throw new IllegalStateException("List is empty");
        }

        int value = head.value;
        head = head.next;

        if (head == null) {
            tail = null;
        } else {
            head.previous = null;
        }

        size--;
        return value;
    }

    // Delete last node
    public int deleteLast() {
        if (tail == null) {
            throw new IllegalStateException("List is empty");
        }

        int value = tail.value;
        tail = tail.previous;

        if (tail == null) {
            head = null;
        } else {
            tail.next = null;
        }

        size--;
        return value;
    }

    // Delete at index
    public int deleteIndex(int index) {

        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Invalid index");
        }

        if (index == 0) {
            return deleteFirst();
        }

        if (index == size - 1) {
            return deleteLast();
        }

        Node current = head;

        for (int i = 0; i < index; i++) {
            current = current.next;
        }

        int value = current.value;

        current.previous.next = current.next;
        current.next.previous = current.previous;

        size--;

        return value;
    }

    // Display forward
    public void display() {
        Node current = head;

        while (current != null) {
            System.out.print(current.value + " -> ");
            current = current.next;
        }

        System.out.println("END");
    }

    // Display backward
    public void displayReverse() {
        Node current = tail;

        while (current != null) {
            System.out.print(current.value + " -> ");
            current = current.previous;
        }

        System.out.println("START");
    }

    public static void main(String[] args) {

        Doubly list = new Doubly();

        list.insertFirst(40);
        list.insertFirst(60);
        list.insertFirst(610);

        list.insertLast(10);

        list.insertIndex(4, 2);

        list.display();
        list.displayReverse();

        System.out.println("Deleted: " + list.deleteFirst());
        list.display();

        System.out.println("Deleted: " + list.deleteLast());
        list.display();

        System.out.println("Deleted: " + list.deleteIndex(1));
        list.display();
        list.displayReverse();
    }
}