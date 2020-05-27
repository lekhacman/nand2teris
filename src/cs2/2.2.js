const iHex = {
    0: 1,
    1: 2,
    2: 4,
    3: 8
}
const hexI = Object.entries(iHex).reduce((obj, [key, value]) => {
    obj[value] = key;
    return obj;
}, {})
const l1 = {
    n: 5, // = 1 + (4 * 1)
    decimal: Math.pow(2, 5),
    hex: '20'
}

const rows = [
    [23, null, null],
    [null, 32768, null],
    [null, null, 2000],
    [12, null, null],
    [null, 64, null],
    [null, null, 100],
]
rows.map(function([n, decimal, hex]) {
    if(n) {
        decimal = Math.pow(2, n);
        hex = powToHexObj(n);
    } else if (decimal) {
        n = Math.log2(decimal);
        hex = powToHexObj(n);
    } else {
        n = powFromHex(hexStruct(hex));
        decimal = Math.pow(2, n);
    }
    const row = [n, decimal, hex];
    console.log(`[ ${n},\t${decimal},\t0x${hex}]`);
    return row;
});

function hexStruct(hex) {
    const arr = hex.toString().split('');
    return {
        i: parseInt(hexI[arr[0]]),
        j: arr.length - 1
    }
}

function powFromHex({i, j}) {
    return i + (4 * j);
}

function powToHexObj(pow) {
    let i, j;
    for (i = 0; i < 4; i++) {
        j = (pow - i) / 4;

        if (isInt(j)) {
            break;
        }
    }
    let hex = `${iHex[i]}`;
    for (let k = 0; k < j; k++) {
        hex += "0";
    }
    return hex;
}

function isInt(num) {
    return (num - parseInt(num)) === 0;
}

const result = [
    [23, 8388608, null],
    [15, 32768, null],
    [null, null, {i: 1, j: 3}],
    [12, 4096, null],
    [6, 64, null],
    [null, null, {i: 0, j: 2}],
]
