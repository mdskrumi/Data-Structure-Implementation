class Cookie {
  constructor(color) {
    this.color = color;
  }
  setColor(color) {
    this.color = color;
  }
  getColor() {
    return this.color;
  }
}

const cookieOne = new Cookie("Green");
console.log(cookieOne);
cookieOne.setColor("Red");
console.log(cookieOne);
