// Stack class to implement a stack data structure
class Stack {
    constructor() {
        // Initialize an empty array to hold stack elements
        this.items = [];
    }

    // Push operation - adds an element to the top of the stack
    push(element) {
        this.items.push(element);
        console.log(`${element} pushed to stack`);
    }

    // Pop operation - removes and returns the top element of the stack
    // Returns undefined if the stack is empty
    pop() {
        if (this.isEmpty()) {
            console.log("Stack is empty, no elements to pop");
            return undefined;
        }
        const poppedElement = this.items.pop();
        console.log(`${poppedElement} popped from stack`);
        return poppedElement;
    }

    // Peek operation - returns the top element of the stack without removing it
    // Returns undefined if the stack is empty
    peek() {
        if (this.isEmpty()) {
            console.log("Stack is empty, no elements to peek");
            return undefined;
        }
        return this.items[this.items.length - 1];
    }

    // isEmpty operation - checks if the stack is empty
    isEmpty() {
        return this.items.length === 0;
    }

    // Print the stack elements
    printStack() {
        if (this.isEmpty()) {
            console.log("Stack is empty");
            return;
        }
        console.log("Stack elements:", this.items.join(" "));
    }
}

// Example usage of the Stack class
const stack = new Stack();

stack.push(10);  // Pushing elements to stack
stack.push(20);
stack.push(30);

stack.printStack();   // Output: Stack elements: 10 20 30

console.log("Top element is:", stack.peek());  // Output: Top element is: 30

stack.pop();   // Removes 30
stack.printStack();   // Output: Stack elements: 10 20

console.log("Top element is:", stack.peek());  // Output: Top element is: 20
console.log("Is stack empty?", stack.isEmpty());  // Output: Is stack empty? false

stack.pop();   // Removes 20
stack.pop();   // Removes 10
stack.pop();   // Stack is empty, no elements to pop
console.log("Is stack empty?", stack.isEmpty());  // Output: Is stack empty? true
