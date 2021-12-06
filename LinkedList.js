class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  constructor(value) {
    const newNode = new Node(value);
    this.head = newNode;
    this.tail = this.head;
    this.length = 1;
  }

  push(value) {
    const newNode = new Node(value);
    if (!this.head) {
      this.head = newNode;
      this.tail = this.head;
      this.length = 1;
    } else {
      this.tail.next = newNode;
      this.tail = newNode;
      this.length = this.length + 1;
    }
  }

  pop() {
    if (this.length === 0 && !this.head) {
      return null;
    }
    let temp = this.head;
    let pre = this.head;
    while (temp.next) {
      pre = temp;
      temp = temp.next;
    }
    this.tail = pre;
    this.tail.next = null;
    this.length = this.length - 1;
    if (this.length === 0) {
      this.head = null;
      this.tail = null;
    }
    return temp;
  }

  unshift(value) {
    const newNode = new Node(value);
    if (!this.head) {
      this.head = newNode;
      this.tail = newNode;
    } else {
      newNode.next = this.head;
      this.head = newNode;
      this.length = this.length + 1;
    }
    return this;
  }

  shift() {
    if (!this.head) {
      return null;
    }
    let temp = head;
    this.head = this.head.next;
    temp.next = null;
    this.length = this.length - 1;
    if (this.length === 0) {
      this.tail = null;
    }
    return temp;
  }

  get(index) {
    if (index < 0 || index >= this.length) {
      return null;
    }
    let temp = this.head;
    for (let i = 0; i < index; i++) {
      temp = temp.next;
    }
    return temp;
  }

  set(index, value) {
    let temp = this.get(index);
    if (temp) {
      temp.value = value;
      return true;
    }
    return false;
  }

  insert(index, value) {
    if (index < 0 || index > this.length) {
      return false;
    } else if (index === 0) {
      return this.unshift(value);
    } else if (index === this.length) {
      return this.push(value);
    } else {
      const newNode = new Node(value);
      const temp = this.get(index - 1);
      newNode.next = temp.next;
      temp.next = newNode;
      this.length = this.length + 1;
      return true;
    }
  }

  remove(index) {
    if (index < 0 || index >= this.length) {
      return false;
    } else if (index === 0) {
      return this.shift();
    } else if (index === this.length - 1) {
      return this.pop();
    } else {
      let before = this.get(index - 1);
      let temp = before.next;
      before.next = temp.next;
      temp.next = null;
      this.length = this.length - 1;
      return temp;
    }
  }

  reverse() {
    let center = this.head;
    this.head = this.tail;
    this.tail = center;
    let prev = null;
    let next = center.next;
    for (let i = 0; i < this.length; i++) {
      next = center.next;
      center.next = prev;
      prev = center;
      center = next;
    }
  }
}

let myLinkedList = new LinkedList(4);
myLinkedList.push(5);
myLinkedList.push(6);
console.log(myLinkedList);
console.log(myLinkedList.reverse());
console.log(myLinkedList);
