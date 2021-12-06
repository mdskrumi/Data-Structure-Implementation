class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
    this.prev = null;
  }
}

class DoublyLinkedList {
  constructor(value) {
    const newNode = new Node(value);
    this.head = newNode;
    this.tail = newNode;
    this.length = 1;
  }

  push(value) {
    const newNode = new Node(value);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      this.tail.next = newNode;
      newNode.prev = this.tail;
      this.tail = newNode;
    }
    this.length++;
    return newNode;
  }

  pop() {
    if (this.length === 0) {
      return null;
    }
    let temp = this.tail;
    this.tail = temp.prev;
    temp.prev = null;
    this.tail.next = null;
    this.length--;
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
    }
    return temp;
  }

  unshift(value) {
    const newNode = new Node(value);
    if (this.length === 0) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head;
      this.head.prev = newNode;
      this.head = newNode;
    }
    this.length++;
    return newNode;
  }

  shift() {
    if (this.length === 0) {
      return null;
    } else {
      let temp = this.head;
      this.head = temp.next;
      temp.next = null;
      this.head.prev = null;
      this.length--;
    }
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
    }
    return temp;
  }
}

let myList = new DoublyLinkedList(10);

myList.push(12);
myList.push(14);

console.log(myList);
