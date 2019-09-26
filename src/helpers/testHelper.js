const fs = require('fs');
const R = require('ramda');

const testPlan = fs.readFileSync('src/1/chips/DMux4Way.cmp', 'utf8');

const data = R.pipe(
  R.split('\n'),
  R.map(R.match(/(?:|)([a-z]+|[0-9]+)(?:|)/gm)),
  R.filter(
    R.compose(
      R.lt(0),
      R.prop('length')
    )
  ),
  function(tests) {
    const makeTest = R.zipObj(R.head(tests));
    return R.pipe(
      R.drop(1),
      R.map(
        R.pipe(
          R.map(
            R.pipe(
              R.split(''),
              R.ifElse(
                R.compose(
                  R.equals(1),
                  R.length
                ),
                R.compose(R.equals('1'), R.head),
                R.map(R.equals('1'))
              )
            )
          ),
          makeTest
        )
      )
    )(tests);
  }
)(testPlan);

fs.writeFileSync('dist/test.json', JSON.stringify(data));
