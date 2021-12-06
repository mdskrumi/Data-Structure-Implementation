function pickingNumbers(a) {
  let ab = a.sort();
  let ans = 0;
  let curr = 0;
  console.log(ab);
  for (let i = 1; i < ab.length; i++) {
    if (Math.abs(ab[i - 1] - ab[i]) === 1) {
      curr++;
    } else {
      ans = ans > curr ? ans : curr;
      curr = 0;
    }
  }
  ans = ans > curr ? ans : curr;
  console.log(ans);
}

pickingNumbers([1, 2, 2, 3, 1, 2]);
