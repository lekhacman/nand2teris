const { nAnd } = require('./bool');
describe('Nand', function() {
  const cases = [
    {
      input: [0, 0],
      want: 1,
    },
    {
      input: [0, 1],
      want: 1,
    },
    {
      input: [1, 0],
      want: 1,
    },
    {
      input: [1, 1],
      want: 0,
    },
  ];

  cases.forEach((c, id) => {
    test(`#${id} Nand`, function() {
      expect(nAnd(...c.input)).toEqual(c.want);
    });
  });
});
