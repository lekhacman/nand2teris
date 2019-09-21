function evalulate(x, y, z) {
  return (x && y) || (!x && z) ? 1 : 0;
}

const cases = [
  [0, 0, 0],
  [0, 0, 1],
  [0, 1, 0],
  [0, 1, 1],
  [1, 0, 0],
  [1, 0, 1],
  [1, 1, 0],
  [1, 1, 1],
];

cases.forEach((c, id) => {
  console.log(`#${id} Result: ${evalulate(...c).toString()}`);
});
