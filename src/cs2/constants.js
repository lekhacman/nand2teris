const binaryHex = {
    '0000': '0',
    '0001': '1',
    '0010': '2',
    '0011': '3',
    '0100': '4',
    '0101': '5',
    '0110': '6',
    '0111': '7',
    '1000': '8',
    '1001': '9',
    '1010': 'a',
    '1011': 'b',
    '1100': 'c',
    '1101': 'd',
    '1110': 'e',
    '1111': 'f',
};

const hexBinary = Object.entries(binaryHex).reduce(
    (map, [key, val]) => {map[val] = key; return map;},
    {}
);

const hexDecimal = {
    '0': '0',
    '1': '1',
    '2': '2',
    '3': '3',
    '4': '4',
    '5': '5',
    '6': '6',
    '7': '7',
    '8': '8',
    '9': '9',
    'a': '10',
    'b': '11',
    'c': '12',
    'd': '13',
    'e': '14',
    'f': '15',
}

const decimalHex = Object.entries(hexDecimal).reduce(
    (map, [key, val]) => {map[val] = key; return map;},
    {}
);

module.exports = {
    binaryHex,
    hexBinary,
    hexDecimal,
    decimalHex,
}
