const hexNotation = {
    '0': '0000',
    '1': '0001',
    '2': '0010',
    '3': '0011',
    '4': '0100',
    '5': '0101',
    '6': '0110',
    '7': '0111',
    '8': '1000',
    '9': '1001',
    'a': '1010',
    'b': '1011',
    'c': '1100',
    'd': '1101',
    'e': '1110',
    'f': '1111',
}
const binaryMap = Object.entries(hexNotation).reduce(
    (map, [h, b]) => {map[b] = h; return map;},
    {}
)
function htob(hex) {
    return hex.toLowerCase().split('').map(c => hexNotation[c]);
}

function btoh(binary) {
    let result = [];
    let chunk = [];
    for(let i = binary.length - 1; i >= 0; i--) {
        chunk.push(binary[i])
        if (chunk.length === 4) {
            result.push(binaryMap[chunk.reverse().join('')])
            chunk = []
        }
    }

    if (chunk.length > 0) {
        while (chunk.length < 4) {
            chunk.push('0');
        }
        result.push(binaryMap[chunk.reverse().join('')])
    }

    return result.reverse().join('');
}

console.log(`A. binary of 0x25B9D2 is ${htob('25B9D2').join(' ')}`);
console.log(`B. hex of 1010111001001001 is 0x${btoh('1010111001001001')}`);
console.log(`C. binary of 0xA8B3D is ${htob('25B9D2').join(' ')}`);
console.log(`D. hex of 1100100010110110010110 is 0x${btoh('1100100010110110010110')}`);

const hexDex = {
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
const dexHex = Object.entries(hexDex).reduce(
    (map, [h, b]) => {map[b] = h; return map;},
    {}
)
function dexToHex(decimal) {

}

function hexToDex(hex) {

}

