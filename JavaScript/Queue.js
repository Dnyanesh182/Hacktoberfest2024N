// Queue class to implement a queue data structure
class Queue {
    constructor() {
        // Initialize an empty array to hold queue elements
        this.items = [];
    }

    // Enqueue operation - adds an element to the end of the queue
    enqueue(element) {
        this.items.push(element);
        console.log(`${element} added to queue`);
    }

    // Dequeue operation - removes and returns the front element of the queue
    // Returns undefined if the queue is empty
    dequeue() {
        if (this.isEmpty()) {
            console.log("Queue is empty, no elements to dequeue");
            return undefined;
        }
        const removedElement = this.items.shift();
        console.log(`${removedElement} removed from queue`);
        return removedElement;
    }

    // Front operation - returns the front element of the queue without removing it
    // Returns undefined if the queue is empty
    front() {
        if (this.isEmpty()) {
            console.log("Queue is empty, no front element");
            return undefined;
        }
        return this.items[0];
    }

    // isEmpty operation - checks if the queue is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Print the queue elements
    printQueue() {
        if (this.isEmpty()) {
            console.log("Queue is empty");
            return;
        }
        console.log("Queue elements:", this.items.join(" "));
    }
}

// Example usage of the Queue class
const queue = new Queue();

queue.enqueue(10);  // Adding elements to the queue
queue.enqueue(20);
queue.enqueue(30);

queue.printQueue();  // Output: Queue elements: 10 20 30

console.log("Front element is:", queue.front());  // Output: Front element is: 10

queue.dequeue();  // Removes 10
queue.printQueue();  // Output: Queue elements: 20 30

console.log("Front element is:", queue.front());  // Output: Front element is: 20
console.log("Is queue empty?", queue.isEmpty());  // Output: Is queue empty? false

queue.dequeue();  // Removes 20
queue.dequeue();  // Removes 30
queue.dequeue();  // Queue is empty, no elements to dequeue
console.log("Is queue empty?", queue.isEmpty());  // Output: Is queue empty? true
