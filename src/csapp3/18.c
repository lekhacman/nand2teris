short test(short x, short y, short z) {
    short val = y + z - x;
    if (z < 5) { // $5 jle z => 5 <= z
        if (y < 2) { // $2 jle y => 2 <= y
            val = x / z;
        } else {
            val = x / y;
        }
    } else if (z > 3) { // $3 jge z => 3 >= z
        val = z / y;
    }

    return val;
}

// Solution
short test(short x, short y, short z) {
    short val = z+y-x;
    if (z > 5) {
        if (y > 2)
            val = x/z;
        else
            val = x/y;
    } else if (z < 3)
        val = z/y;
    return val;
}
