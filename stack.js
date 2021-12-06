class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Stack {
  constructor(value) {
    const newNode = new Node(value);
    this.top = newNode;
    this.length = 1;
  }

  push(value) {
    const newNode = new Node(value);
    if (this.length === 0) {
      this.top = newNode;
    } else {
      newNode.next = this.top;
      this.top = newNode;
    }
    this.length += 1;
    return this;
  }

  pop() {
    if (this.length === 0) {
      return null;
    } else {
      let temp = this.top;
      this.top = temp.next;
      temp.next = null;
      this.length--;
      return temp;
    }
  }
}

let myStack = new Stack(10);
myStack.push(12);
myStack.push(11);
myStack.push(13);
myStack.pop();
console.log(myStack);
