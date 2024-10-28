// Node class to represent each element in the linked list
class Node {
    constructor(value) {
        this.value = value; // Node data
        this.next = null; // Pointer to the next node in the list
    }
}

// LinkedList class to handle operations on the linked list
class LinkedList {
    constructor() {
        this.head = null; // Head pointer to the first node in the list
    }

    // Append operation - adds a new node with the given value at the end of the list
    append(value) {
        const newNode = new Node(value);

        if (this.head === null) {  // If the list is empty
            this.head = newNode;  // Make the new node the head
        } else {
            let current = this.head;
            while (current.next !== null) {  // Traverse to the last node
                current = current.next;
            }
            current.next = newNode;  // Add the new node at the end
        }
        console.log(`Appended ${value} to the list.`);
    }

    // Prepend operation - adds a new node with the given value at the beginning of the list
    prepend(value) {
        const newNode = new Node(value);
        newNode.next = this.head;  // Make the new node point to the current head
        this.head = newNode;  // Update the head to the new node
        console.log(`Prepended ${value} to the list.`);
    }

    // Remove operation - removes the first node with the specified value from the list
    remove(value) {
        if (this.head === null) {  // If the list is empty
            console.log("List is empty.");
            return;
        }

        if (this.head.value === value) {  // If the head node has the target value
            this.head = this.head.next;  // Update head to the next node
            console.log(`Removed ${value} from the list.`);
            return;
        }

        let current = this.head;
        while (current.next !== null && current.next.value !== value) {  // Traverse to find the target value
            current = current.next;
        }

        if (current.next === null) {  // If the value was not found
            console.log(`${value} not found in the list.`);
        } else {  // If the value was found
            current.next = current.next.next;  // Bypass the node with the target value
            console.log(`Removed ${value} from the list.`);
        }
    }

    // Print List operation - displays all nodes in the linked list
    printList() {
        if (this.head === null) {
            console.log("List is empty.");
            return;
        }

        let current = this.head;
        let listValues = "";
        while (current !== null) {  // Traverse and collect values
            listValues += current.value + " -> ";
            current = current.next;
        }
        listValues += "null";  // Indicate end of list
        console.log("Linked List:", listValues);
    }
}

// Example usage of the LinkedList class
const list = new LinkedList();

list.append(10);  // Adding elements to the end
list.append(20);
list.append(30);

list.printList();  // Output: Linked List: 10 -> 20 -> 30 -> null

list.prepend(5);  // Adding an element to the beginning
list.printList();  // Output: Linked List: 5 -> 10 -> 20 -> 30 -> null

list.remove(20);  // Removing a node with value 20
list.printList();  // Output: Linked List: 5 -> 10 -> 30 -> null

list.remove(50);  // Trying to remove a non-existing node
list.printList();  // Output: Linked List: 5 -> 10 -> 30 -> null
