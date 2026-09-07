package PERSONAL.JAVA;

// Node structure with initialised value
class Node{
    int val;
    Node next;
    Node (int d){
        val = d;
        next = null;
    }
}


// Structure to represent stack
class LinkedListStack{
    private Node head; // Top of Stack
    private int size; // size

    public LinkedListStack(){
        head = null;
        size = 0;
    }

}