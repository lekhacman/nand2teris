const R = require('ramda');

function nAnd(_x, _y) {
  const isOne = R.equals(1);
  const x = isOne(_x);
  const y = isOne(_y);

  return R.pipe(
    R.not,
    R.ifElse(R.identity, R.always(1), R.always(0))
  )(R.and(x, y));
}

module.exports = {
  nAnd,
};
