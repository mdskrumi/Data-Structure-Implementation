class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class Queue {
  constructor(value) {
    const newNode = new Node(value);
    this.first = newNode;
    this.last = newNode;
    this.length = 1;
  }

  enqueue(value) {
    const newNode = new Node(value);
    if (this.length === 0) {
      this.first = newNode;
      this.last = newNode;
      this.length = 1;
    } else {
      this.last.next = newNode;
      this.last = newNode;
    }
    this.length++;
    return this;
  }

  dequeue() {
    if (this.length === 0) {
      return null;
    }
    if (this.length === 1) {
      let temp = this.first;
      this.first = null;
      this.last = null;
      this.length--;
      return temp;
    } else {
      let temp = this.first;
      this.first = temp.next;
      this.length--;
      return temp;
    }
  }
}

let myQueue = new Queue(10);
myQueue.enqueue(20);
myQueue.enqueue(30);
myQueue.enqueue(40);
myQueue.enqueue(12);
myQueue.dequeue();
myQueue.dequeue();

console.log(myQueue);
