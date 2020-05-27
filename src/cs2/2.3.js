const {binaryHex, hexBinary, hexDecimal, decimalHex} = require('./constants');

const data = [
    {d: 158, b: [], h: null},
    {d: 76, b: [], h: null},
    {d: 145, b: [], h: null},
    {d: null, b: ["1010", "1110"], h: null},
    {d: null, b: ["0011", "1100"], h: null},
    {d: null, b: ["1111", "0001"], h: null},
    {d: null, b: [], h: '75'},
    {d: null, b: [], h: 'bd'},
    {d: null, b: [], h: 'f5'},
];

data.forEach(({d, b, h}) => {
    if (d) {
        h = decimalToHex(d);
        b = h.split('').map(hex => hexBinary[hex]);
    } else if (h) {
        b = h.split('').map(hex => hexBinary[hex]);
        d = hexToDecimal(h);
    } else {
        h = b.map(bits => binaryHex[bits]).join('');
        d = hexToDecimal(h);
    }

    console.log(`[ ${d},\t${b.join(' ')},  0x${h}]`);
})

function decimalToHex(decimal) {
    let hex = [];
    let q = decimal;
    let r;

    do {
        r = q % 16;
        hex.push(decimalHex[r]);
        q = parseInt(q / 16);
    } while (q > 15)

    hex.push(decimalHex[q]);

    return hex.reverse().join('');
}

function hexToDecimal(hex) {
    return hex.split('').map(h => parseInt(hexDecimal[h])).reduce(
        (acc, decimal, id) => {
            return acc + (decimal * Math.pow(16, hex.length - 1 - id));
        },
        0
    );
}

// Solution
// Decimal                 Binary       Hexadecimal
// 0                       0000 0000    0x00
// 158 = 16 . 9 + 14       1001 1110    0x9E
// 76 = 16 . 4 + 12        0100 1100    0x4C
// 145 = 16 . 9 + 1        1001 0001    0x91
// 16 . 10 + 14 = 174      1010 1110    0xAE
// 16 . 3 + 12 = 60        0011 1100    0x3C
// 16 . 15 + 1 = 241       1111 0001    0xF1
// 16 . 7 + 5 = 117        0111 0101    0x75
// 16 . 11 + 13 = 189      1011 1101    0xBD
// 16 . 15 + 5 = 245       1111 0101    0xF5
