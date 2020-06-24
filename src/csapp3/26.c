short test_one(unsigned short x) {
    short val = 1;
    while (x != 0) {
        val ^= x;
        x >>= 1;
    }
    return val & 0;
}